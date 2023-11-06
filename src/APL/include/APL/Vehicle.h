#pragma once

#include <memory>
#include <string>

#include <APL/Constants.h>

namespace APL
{
	// Class representing a Vehicle
	class Vehicle
	{
	public:
		// Constructor for a Vehicle object
		Vehicle(const std::string& _licensePlate, VehicleType _vehicleType, int _parkingDuration);
		// Virtual destructor for Vehicle (to allow for derived classes)
		virtual ~Vehicle();

		// Getter functions for the vehicle properties
		const std::string& getLicensePlate() const;
		VehicleType getVehicleType() const;
		int getParkingDuration() const;

		// Pure virtual function to calculate the charge (to be implemented by derived classes)
		virtual float calculateCharge() const = 0;

	private:
		std::string m_licensePlate;
		VehicleType m_vehicleType;
		int m_parkingDuration;
	};

	// Define a shared pointer type for Vehicle objects
	typedef std::shared_ptr<Vehicle> VehiclePtr;

	// Abstract class for creating Vehicle objects
	class VehicleFactory
	{
	public:
		// Pure virtual function to create a Vehicle object (to be implemented by derived classes)
		virtual VehiclePtr createVehicle(const std::string& _licensePlate, int _parkingDuration) = 0;
	};

	// Define a shared pointer type for VehicleFactory objects
	typedef std::shared_ptr<VehicleFactory> VehicleFactoryPtr;
}