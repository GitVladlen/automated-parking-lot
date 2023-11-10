#include <APL/ParkingLot.h>
#include <APL/Exceptions.h>
#include <APL/Logger.h>
#include <APL/UUIDGenerator.h>

namespace APL
{
	ParkingLot::ParkingLot()
	{
		// Creating default ticket generator as UUIDGeneratorFactory
		UUIDGeneratorFactory generatorFactory;
		m_ticketGenerator = generatorFactory.createGenerator();
	}

	ParkingLot::ParkingLot(const IUniqueIDGeneratorPtr& _ticketGenerator)
		: m_ticketGenerator(_ticketGenerator)
	{
	}

	void ParkingLot::setTicketGenerator(const IUniqueIDGeneratorPtr& _ticketGenerator)
	{
		m_ticketGenerator = _ticketGenerator;
	}

	// Set the capacity for a specific vehicle type
	void ParkingLot::setVehicleTypeCapacity(VehicleType _vehicleType, int _capacity)
	{
		if (_capacity < 0)
		{
			throw NegativeCapacityException(_vehicleType, _capacity);
		}

		std::lock_guard<std::mutex> lock(m_capacityAccessMutex);
		m_vehicleCapacity[_vehicleType] = _capacity;
	}

	// Get the number of available parking slots for a specific vehicle type
	int ParkingLot::getAvailableSlots(VehicleType _vehicleType) const
	{
		std::lock_guard<std::mutex> lock(m_capacityAccessMutex);

		if (auto search = m_vehicleCapacity.find(_vehicleType); search != m_vehicleCapacity.end())
		{
			return search->second;
		}

		throw InvalidVehicleTypeException(_vehicleType);
	}

	// Park a vehicle and generate a ticket
	std::string ParkingLot::parkVehicle(const VehiclePtr& _vehicle)
	{
		VehicleType vehicleType = _vehicle->getVehicleType();

		std::unique_lock<std::mutex> capacityLock(m_capacityAccessMutex);

		if (m_vehicleCapacity.find(vehicleType) == m_vehicleCapacity.end())
		{
			throw InvalidVehicleTypeException(vehicleType);
		}

		if (m_vehicleCapacity[vehicleType] <= 0)
		{
			throw OutOfVehicleCapacityException(vehicleType);
		}

		--m_vehicleCapacity[vehicleType];

		capacityLock.unlock();

		std::string ticket = m_ticketGenerator->generateUniqueID();

		std::unique_lock<std::mutex> ticketLock(m_ticketAccessMutex);
		m_ticketToVehicle[ticket] = _vehicle;
		ticketLock.unlock();

		LOG_INFO_FMT("Parked a %s %s - ticket: %s"
			, APL::vehicleTypeToString(vehicleType).c_str()
			, _vehicle->getLicensePlate().c_str()
			, ticket.c_str());

		return ticket;
	}

	// Release a parked vehicle and calculate the charge
	float ParkingLot::releaseVehicle(const std::string& _ticket)
	{
		std::unique_lock<std::mutex> ticketLock(m_ticketAccessMutex);

		if (m_ticketToVehicle.find(_ticket) == m_ticketToVehicle.end())
		{
			throw InvalidTicketIDException(_ticket);
		}

		const VehiclePtr& vehicle = m_ticketToVehicle[_ticket];
		
		ticketLock.unlock();
		
		float charge = vehicle->calculateCharge();

		LOG_INFO_FMT("Release a %s %s - ticket: %s - charge $%.2f"
			, APL::vehicleTypeToString(vehicle->getVehicleType()).c_str()
			, vehicle->getLicensePlate().c_str()
			, _ticket.c_str()
			, charge);
		
		std::unique_lock<std::mutex> capacityLock(m_capacityAccessMutex);

		++m_vehicleCapacity[vehicle->getVehicleType()];
		capacityLock.unlock();

		ticketLock.lock();
		m_ticketToVehicle.erase(_ticket);
		ticketLock.unlock();

		return charge;
	}

	// Calculate the charge for a parked vehicle based on the ticket ID
	float ParkingLot::calculateCharge(const std::string& _ticket)
	{
		std::unique_lock<std::mutex> ticketLock(m_ticketAccessMutex);

		if (m_ticketToVehicle.find(_ticket) == m_ticketToVehicle.end())
		{
			throw InvalidTicketIDException(_ticket);
		}

		const VehiclePtr& vehicle = m_ticketToVehicle[_ticket];

		ticketLock.unlock();

		return vehicle->calculateCharge();
	}
}
