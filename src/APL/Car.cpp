#include <APL/Car.h>

namespace APL
{
	Car::Car(const std::string& _licensePlate, int _parkingDuration)
		: Vehicle(_licensePlate, VehicleType::Car, _parkingDuration)
	{
	}

	// Calculate the parking charge for a Car based on the parking duration
	float Car::calculateCharge() const
	{
		int parkingDuration = getParkingDuration();

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