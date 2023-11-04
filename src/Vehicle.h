#pragma once

#include <chrono>
#include <memory>
#include <string>

#include "Constants.h"

namespace APL
{
	class Vehicle
	{
	public:
		Vehicle(const std::string& _licensePlate, VehicleType _vehicleType);
		virtual ~Vehicle();

		const std::string& getLicensePlate() const;
		VehicleType getVehicleType() const;

		void updateParkingTimestamp();
		int calculateParkingDuration() const;

		virtual float calculateCharge() const = 0;

	private:
		std::string m_licensePlate;
		VehicleType m_vehicleType;
		std::chrono::time_point<std::chrono::system_clock> m_parkingTimestamp;
	};

	typedef std::shared_ptr<Vehicle> VehiclePtr;
}