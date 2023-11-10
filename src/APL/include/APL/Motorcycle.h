#pragma once

#include <APL/Vehicle.h>

namespace APL
{
	class Motorcycle : public Vehicle
	{
	public:
		// Constructor for Motorcycle, taking license plate and parking duration in hours
		Motorcycle(const std::string& _licensePlate, int _parkingDuration);

	protected:
		virtual float getBaseCharge() const override;
		virtual float getAdditionalChargePerHour() const override;
	};

	class MotorcycleFactory : public VehicleFactory
	{
	public:
		// Create a Motorcycle instance with the given license plate and parking timestamp
		VehiclePtr createVehicle(const std::string& _licensePlate, int _parkingDuration) override
		{
			return std::make_shared<Motorcycle>(_licensePlate, _parkingDuration);
		}
	};
}
