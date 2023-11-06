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
	Vehicle::Vehicle(const std::string& _licensePlate, VehicleType _vehicleType, int _parkingDuration)
		: m_licensePlate(_licensePlate)
		, m_vehicleType(_vehicleType)
		, m_parkingDuration(_parkingDuration)
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

	// Getter function for the parking duration in hours
	int Vehicle::getParkingDuration() const
	{
		return m_parkingDuration;
	}
}
