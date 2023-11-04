#pragma once

#include "Vehicle.h"

namespace APL
{
	class Car : public Vehicle
	{
	public:
		Car(const std::string& _licensePlate);

		virtual float calculateCharge() const override;
	};
}