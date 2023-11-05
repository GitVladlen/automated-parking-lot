#pragma once

#include <APL/Vehicle.h>

namespace APL
{
	class Motorcycle : public Vehicle
	{
	public:
		Motorcycle(const std::string& _licensePlate, const Timestamp& _parkingTimestamp);

		virtual float calculateCharge() const override;
	};

	class MotorcycleFactory : public VehicleFactory
	{
	public:
		VehiclePtr createVehicle(const std::string& _licensePlate, const Timestamp& _parkingTimestamp) override
		{
			return std::make_shared<Motorcycle>(_licensePlate, _parkingTimestamp);
		}
	};
}