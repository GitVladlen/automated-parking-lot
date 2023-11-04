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
}