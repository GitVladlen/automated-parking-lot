#pragma once

#include <APL/Vehicle.h>

namespace APL
{
	class Car : public Vehicle
	{
	public:
		// Constructor for Car, taking license plate and parking duration in hours
		Car(const std::string& _licensePlate, int _parkingDuration);

		// Calculate the parking charge for a Car
		virtual float calculateCharge() const override;
	};

	class CarFactory : public VehicleFactory
	{
	public:
		// Create a Car instance with the given license plate and parking duration in hours
		VehiclePtr createVehicle(const std::string& _licensePlate, int _parkingDuration) override
		{
			return std::make_shared<Car>(_licensePlate, _parkingDuration);
		}
	};
}
