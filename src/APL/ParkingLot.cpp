#include <APL/ParkingLot.h>
#include <APL/Exceptions.h>
#include <APL/UniqueIDGenerator.h>
#include <APL/Logger.h>

namespace APL
{
	ParkingLot::ParkingLot()
	{
	}

	// Set the capacity for a specific vehicle type
	void ParkingLot::setVehicleTypeCapacity(VehicleType _vehicleType, int _capacity)
	{
		if (_capacity < 0)
		{
			throw NegativeCapacityException(_vehicleType, _capacity);
		}

		std::lock_guard<std::mutex> lock(capacityAccessMutex);
		m_vehicleCapacity[_vehicleType] = _capacity;
	}

	// Get the number of available parking slots for a specific vehicle type
	int ParkingLot::getAvailableSlots(VehicleType _vehicleType) const
	{
		std::lock_guard<std::mutex> lock(capacityAccessMutex);

		if (auto search = m_vehicleCapacity.find(_vehicleType); search != m_vehicleCapacity.end())
		{
			return search->second;
		}

		throw InvalidVehicleTypeException(_vehicleType);
	}

	// Park a vehicle and generate a ticket
	int ParkingLot::parkVehicle(const VehiclePtr& _vehicle)
	{
		VehicleType vehicleType = _vehicle->getVehicleType();

		std::lock(vehicleAccessMutex, capacityAccessMutex, ticketAccessMutex);

		std::lock_guard<std::mutex> vehicleLock(vehicleAccessMutex, std::adopt_lock);
		std::lock_guard<std::mutex> capacityLock(capacityAccessMutex, std::adopt_lock);
		std::lock_guard<std::mutex> ticketLock(ticketAccessMutex, std::adopt_lock);

		if (m_vehicleCapacity.find(vehicleType) == m_vehicleCapacity.end())
		{
			throw InvalidVehicleTypeException(vehicleType);
		}

		if (m_vehicleCapacity[vehicleType] <= 0)
		{
			throw OutOfVehicleCapacityException(vehicleType);
		}

		--m_vehicleCapacity[vehicleType];
		m_parkedVehicles.push_back(_vehicle);
		UniqueIDGenerator& uniqueIdGenerator = UniqueIDGenerator::getInstance();
		int ticketID = uniqueIdGenerator.generateUniqueID();
		m_ticketToVehicle[ticketID] = _vehicle;

		LOG_INFO_FMT("Parked a %s %s - ticket %i"
			, APL::vehicleTypeToString(vehicleType).c_str()
			, _vehicle->getLicensePlate().c_str()
			, ticketID);

		return ticketID;
	}

	// Release a parked vehicle and calculate the charge
	float ParkingLot::releaseVehicle(int _ticketId)
	{
		std::lock(vehicleAccessMutex, capacityAccessMutex, ticketAccessMutex);

		std::lock_guard<std::mutex> vehicleLock(vehicleAccessMutex, std::adopt_lock);
		std::lock_guard<std::mutex> capacityLock(capacityAccessMutex, std::adopt_lock);
		std::lock_guard<std::mutex> ticketLock(ticketAccessMutex, std::adopt_lock);

		if (m_ticketToVehicle.find(_ticketId) == m_ticketToVehicle.end())
		{
			throw InvalidTicketIDException(_ticketId);
		}

		const VehiclePtr& vehicle = m_ticketToVehicle[_ticketId];
		float charge = vehicle->calculateCharge();

		LOG_INFO_FMT("Release a %s %s - ticket %i - charge $%.2f"
			, APL::vehicleTypeToString(vehicle->getVehicleType()).c_str()
			, vehicle->getLicensePlate().c_str()
			, _ticketId, charge);

		++m_vehicleCapacity[vehicle->getVehicleType()];
		m_parkedVehicles.erase(std::remove(m_parkedVehicles.begin(), m_parkedVehicles.end(), vehicle), m_parkedVehicles.end());
		m_ticketToVehicle.erase(_ticketId);

		return charge;
	}

	// Calculate the charge for a parked vehicle based on the ticket ID
	float ParkingLot::calculateCharge(int _ticketId)
	{
		std::lock_guard<std::mutex> vehicleLock(ticketAccessMutex);

		if (m_ticketToVehicle.find(_ticketId) == m_ticketToVehicle.end())
		{
			throw InvalidTicketIDException(_ticketId);
		}

		const VehiclePtr& vehicle = m_ticketToVehicle[_ticketId];

		return vehicle->calculateCharge();
	}
}
