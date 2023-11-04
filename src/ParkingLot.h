#pragma once

#include <unordered_map>
#include <vector>

#include "Vehicle.h"

namespace APL
{
	class ParkingLot
	{
	public:
		ParkingLot(int _carCapacity, int _motorcycleCapacity, int _busCapacity);

		int parkVehicle(const VehiclePtr& _vehicle);
		float releaseVehicle(int _ticketId);

		int getAvailableCarSlots() const;
		int getAvailableMotorcycleSlots() const;
		int getAvailableBusSlots() const;

	private:
		int m_carCapacity;
		int m_motorcycleCapacity;
		int m_busCapacity;
		std::vector<VehiclePtr> m_parkedVehicles;
		std::unordered_map<int, VehiclePtr> m_ticketToVehicle;
	};
}