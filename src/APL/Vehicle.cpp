// Vehicle.cpp
#pragma once

#include <chrono>
#include <memory>
#include <string>

#include <APL/Vehicle.h>
#include <APL/Constants.h>

namespace APL
{
	// Constructor for a Vehicle object
	Vehicle::Vehicle(const std::string& _licensePlate, VehicleType _vehicleType, const Timestamp& _parkingTimestamp)
		: m_licensePlate(_licensePlate)
		, m_vehicleType(_vehicleType)
		, m_parkingTimestamp(_parkingTimestamp)
	{
	}

	// Virtual destructor for Vehicle
	Vehicle::~Vehicle()
	{
	}

	// Getter function for the license plate
	const std::string& Vehicle::getLicensePlate() const
	{
		return m_licensePlate;
	}

	// Getter function for the vehicle type
	VehicleType Vehicle::getVehicleType() const
	{
		return m_vehicleType;
	}

	// Getter function for the parking timestamp
	const Timestamp& Vehicle::getParkingTimestamp() const
	{
		return m_parkingTimestamp;
	}

	// Calculate the parking duration in hours
	int Vehicle::calculateParkingDuration() const
	{
		auto now = std::chrono::system_clock::now();
		return std::chrono::duration_cast<std::chrono::hours>(now - m_parkingTimestamp).count();
	}
}
