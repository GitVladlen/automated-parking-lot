#pragma once

#include <chrono>
#include <memory>
#include <string>

#include <APL/Constants.h>

namespace APL
{
	typedef std::chrono::time_point<std::chrono::system_clock> Timestamp;

	class Vehicle
	{
	public:
		Vehicle(const std::string& _licensePlate, VehicleType _vehicleType, const Timestamp& _parkingTimestamp);
		virtual ~Vehicle();

		const std::string& getLicensePlate() const;
		VehicleType getVehicleType() const;
		const Timestamp& getParkingTimestamp() const;

		int calculateParkingDuration() const;
	
		virtual float calculateCharge() const = 0;

	private:
		std::string m_licensePlate;
		VehicleType m_vehicleType;
		Timestamp m_parkingTimestamp;
	};

	typedef std::shared_ptr<Vehicle> VehiclePtr;
}