#pragma once

#include "Vehicle.h"

namespace APL
{
	class Bus : public Vehicle
	{
	public:
		Bus(const std::string& _licensePlate);

		virtual float calculateCharge() const override;
	};
}