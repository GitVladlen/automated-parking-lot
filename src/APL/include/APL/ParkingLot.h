#pragma once

#include <unordered_map>
#include <vector>
#include <mutex>

#include <APL/Vehicle.h>
#include <APL/IUniqueIDGenerator.h>

namespace APL
{
	class ParkingLot
	{
	public:
		ParkingLot();
		ParkingLot(const IUniqueIDGeneratorPtr& _ticketGenerator);
		
		// Set the ticket generator
		void setTicketGenerator(const IUniqueIDGeneratorPtr& _ticketGenerator);

		// Set the capacity for a specific vehicle type
		void setVehicleTypeCapacity(VehicleType _vehicleType, int _capacity);

		// Get the number of available parking slots for a specific vehicle type
		int getAvailableSlots(VehicleType _vehicleType) const;

		// Park a vehicle and generate a ticket
		std::string parkVehicle(const VehiclePtr& _vehicle);

		// Release a parked vehicle and calculate the charge
		float releaseVehicle(const std::string& _ticket);

		// Calculate the charge for a parked vehicle based on the ticket ID
		float calculateCharge(const std::string& _ticket);

	private:
		std::unordered_map<VehicleType, int> m_vehicleCapacity;
		std::unordered_map<std::string, VehiclePtr> m_ticketToVehicle;
		IUniqueIDGeneratorPtr m_ticketGenerator;

		mutable std::mutex m_capacityAccessMutex;
		mutable std::mutex m_ticketAccessMutex;
	};
}
