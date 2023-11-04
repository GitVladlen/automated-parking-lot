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
}