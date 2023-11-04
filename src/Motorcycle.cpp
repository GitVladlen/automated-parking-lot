#include "Motorcycle.h"

namespace APL
{
	Motorcycle::Motorcycle(const std::string& _licensePlate)
		: Vehicle(_licensePlate, VehicleType::Motorcycle)
	{
	}

	float Motorcycle::calculateCharge() const
	{
		int parkingDuration = calculateParkingDuration();

		if (parkingDuration <= 1)
		{
			return 1.0f;
		}
		else
		{
			return 1.0f + (parkingDuration - 1) * 0.5f;
		}
	}
}