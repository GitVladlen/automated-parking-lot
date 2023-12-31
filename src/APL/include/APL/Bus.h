#pragma once

#include <APL/Vehicle.h>

namespace APL
{
	class Bus : public Vehicle
	{
	public:
		// Constructor for Bus, taking license plate and parking duration in hours
		Bus(const std::string& _licensePlate, int _parkingDuration);

	protected:
		virtual float getBaseCharge() const override;
		virtual float getAdditionalChargePerHour() const override;
	};

	class BusFactory : public VehicleFactory
	{
	public:
		// Create a Bus instance with the given license plate and parking duration in hours
		VehiclePtr createVehicle(const std::string& _licensePlate, int _parkingDuration) override
		{
			return std::make_shared<Bus>(_licensePlate, _parkingDuration);
		}
	};
}
