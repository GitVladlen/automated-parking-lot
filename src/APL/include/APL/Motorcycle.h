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
}