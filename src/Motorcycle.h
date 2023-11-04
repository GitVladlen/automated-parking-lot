#pragma once

#include "Vehicle.h"

namespace APL
{
	class Motorcycle : public Vehicle
	{
	public:
		Motorcycle(const std::string& _licensePlate);

		virtual float calculateCharge() const override;
	};
}