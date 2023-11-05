#pragma once

#include <APL/Vehicle.h>

namespace APL
{
	class Car : public Vehicle
	{
	public:
		Car(const std::string& _licensePlate, const Timestamp& _parkingTimestamp);

		virtual float calculateCharge() const override;
	};

	class CarFactory : public VehicleFactory
	{
	public:
		VehiclePtr createVehicle(const std::string& _licensePlate, const Timestamp& _parkingTimestamp) override
		{
			return std::make_shared<Car>(_licensePlate, _parkingTimestamp);
		}
	};
}