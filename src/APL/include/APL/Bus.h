#pragma once

#include <APL/Vehicle.h>

namespace APL
{
	class Bus : public Vehicle
	{
	public:
		Bus(const std::string& _licensePlate, const Timestamp& _parkingTimestamp);

		virtual float calculateCharge() const override;
	};

	class BusFactory : public VehicleFactory
	{
	public:
		VehiclePtr createVehicle(const std::string& _licensePlate, const Timestamp& _parkingTimestamp) override
		{
			return std::make_shared<Bus>(_licensePlate, _parkingTimestamp);
		}
	};
}