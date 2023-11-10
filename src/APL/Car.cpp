#include <APL/Car.h>

namespace APL
{
	Car::Car(const std::string& _licensePlate, int _parkingDuration)
		: Vehicle(_licensePlate, VehicleType::Car, _parkingDuration)
	{
	}

	float Car::getBaseCharge() const
	{
		return 2.0f;
	}

	float Car::getAdditionalChargePerHour() const
	{
		return 1.0f;
	}
}