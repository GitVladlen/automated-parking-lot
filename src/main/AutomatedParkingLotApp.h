#pragma once

#include <unordered_map>

#include <APL/ParkingLot.h>

namespace App
{
	class AutomatedParkingLotApp
	{
	public:
		AutomatedParkingLotApp();

		// Run the automated parking lot application
		int run();

	private:
		// Create a vehicle of the specified type
		APL::VehiclePtr createVehicle(APL::VehicleType _vehicleType, const std::string& _licensePlate, int _parkingDuration);

	private:
		// Run a parking simulation with a specified number of vehicles
		void runParkingSimulation(int _vehicleCount);

	private:
		APL::ParkingLot m_parkingLot; // The parking lot where vehicles are managed.
		std::unordered_map<APL::VehicleType, APL::VehicleFactoryPtr> m_vehicleFactories; // Factories for creating vehicles of different types.
	};
}