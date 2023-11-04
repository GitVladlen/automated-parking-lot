#include <APL/Car.h>

namespace APL
{
	Car::Car(const std::string& _licensePlate, const Timestamp& _parkingTimestamp)
		: Vehicle(_licensePlate, VehicleType::Car, _parkingTimestamp)
	{
	}

	float Car::calculateCharge() const
	{
		int parkingDuration = calculateParkingDuration();

		if (parkingDuration <= 1)
		{
			return 2.0f;
		}
		else
		{
			return 2.0f + (parkingDuration - 1) * 1.0f;
		}
	}
}