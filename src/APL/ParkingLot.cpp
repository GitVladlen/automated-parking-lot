#include <APL/ParkingLot.h>
#include <APL/Utils.h>

namespace APL
{
	ParkingLot::ParkingLot(int _carCapacity, int _motorcycleCapacity, int _busCapacity)
		: m_carCapacity(_carCapacity)
		, m_motorcycleCapacity(_motorcycleCapacity)
		, m_busCapacity(_busCapacity)
	{
	}

	int ParkingLot::parkVehicle(const VehiclePtr& _vehicle)
	{
		// TODO: refactor this code dublicates
		// TODO: add exceptions
		if (_vehicle->getVehicleType() == VehicleType::Car && m_carCapacity > 0)
		{
			m_carCapacity--;

			m_parkedVehicles.push_back(_vehicle);
			Utils::UniqueIDGenerator& uniqueIdGenerator = Utils::UniqueIDGenerator::getInstance();
			int ticketID = uniqueIdGenerator.generateUniqueID();
			m_ticketToVehicle[ticketID] = _vehicle;

			return ticketID;
		}
		else if (_vehicle->getVehicleType() == VehicleType::Motorcycle && m_motorcycleCapacity > 0)
		{
			m_motorcycleCapacity--;

			m_parkedVehicles.push_back(_vehicle);
			Utils::UniqueIDGenerator& uniqueIdGenerator = Utils::UniqueIDGenerator::getInstance();
			int ticketID = uniqueIdGenerator.generateUniqueID();
			m_ticketToVehicle[ticketID] = _vehicle;

			return ticketID;
		}
		else if (_vehicle->getVehicleType() == VehicleType::Bus && m_busCapacity > 0)
		{
			m_busCapacity--;

			m_parkedVehicles.push_back(_vehicle);
			Utils::UniqueIDGenerator& uniqueIdGenerator = Utils::UniqueIDGenerator::getInstance();
			int ticketID = uniqueIdGenerator.generateUniqueID();
			m_ticketToVehicle[ticketID] = _vehicle;

			return ticketID;
		}

		return -1;
	}

	float ParkingLot::releaseVehicle(int _ticketId)
	{
		if (m_ticketToVehicle.find(_ticketId) != m_ticketToVehicle.end())
		{
			const VehiclePtr& vehicle = m_ticketToVehicle[_ticketId];
			float charge = vehicle->calculateCharge();
			// TODO: can we avoid this switch here? maybe do some refactor here
			switch (vehicle->getVehicleType())
			{
			case VehicleType::Car:
			{
				m_carCapacity++;
				break;
			}
			case VehicleType::Motorcycle:
			{
				m_motorcycleCapacity++;
				break;
			}
			case VehicleType::Bus:
			{
				m_busCapacity++;
				break;
			}
			}
			m_parkedVehicles.erase(std::remove(m_parkedVehicles.begin(), m_parkedVehicles.end(), vehicle), m_parkedVehicles.end());
			m_ticketToVehicle.erase(_ticketId);
			return charge;
		}

		return -1.0; // TODO: exception
	}

	int ParkingLot::getAvailableCarSlots() const
	{
		return m_carCapacity;
	}

	int ParkingLot::getAvailableMotorcycleSlots() const
	{
		return m_motorcycleCapacity;
	}

	int ParkingLot::getAvailableBusSlots() const
	{
		return m_busCapacity;
	}
}