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

		// Set the capacity for a specific vehicle type
		void setVehicleTypeCapacity(VehicleType _vehicleType, int _capacity);

		// Get the number of available parking slots for a specific vehicle type
		int getAvailableSlots(VehicleType _vehicleType) const;

		// Park a vehicle and generate a ticket
		int parkVehicle(const VehiclePtr& _vehicle);

		// Release a parked vehicle and calculate the charge
		float releaseVehicle(int _ticketId);

		// Calculate the charge for a parked vehicle based on the ticket ID
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
