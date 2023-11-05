#pragma once

#include <APL/ParkingLot.h>
#include <unordered_map>

namespace App
{
	class AutomatedParkingLotApp
	{
	public:
		AutomatedParkingLotApp();

		int run();

	private:
		APL::VehiclePtr createVehicle(APL::VehicleType _vehicleType, const std::string& _licensePlate, const APL::Timestamp& _parkingTimestamp);

	private:
		APL::ParkingLot m_parkingLot;
		std::unordered_map<APL::VehicleType, APL::VehicleFactoryPtr> m_vehicleFactories;
	};
}