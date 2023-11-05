#pragma once

#include <unordered_map>
#include <vector>
#include <mutex>

#include <APL/Vehicle.h>

namespace APL
{
	class ParkingLot
	{
	public:
		ParkingLot();

		void setVehicleTypeCapacity(VehicleType _vehicleType, int _capacity);
		int getAvailableSlots(VehicleType _vehicleType) const;

		int parkVehicle(const VehiclePtr& _vehicle);
		float releaseVehicle(int _ticketId);
		float calculateCharge(int _ticketId);

	private:
		std::vector<VehiclePtr> m_parkedVehicles;
		std::unordered_map<VehicleType, int> m_vehicleCapacity;
		std::unordered_map<int, VehiclePtr> m_ticketToVehicle;

		mutable std::mutex vehicleAccessMutex;
		mutable std::mutex capacityAccessMutex;
		mutable std::mutex ticketAccessMutex;
	};
}