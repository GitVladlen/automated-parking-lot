#include <APL/Motorcycle.h>

namespace APL
{
	Motorcycle::Motorcycle(const std::string& _licensePlate, int _parkingDuration)
		: Vehicle(_licensePlate, VehicleType::Motorcycle, _parkingDuration)
	{
	}

	float Motorcycle::getBaseCharge() const
	{
		return 1.0f;
	}

	float Motorcycle::getAdditionalChargePerHour() const
	{
		return 0.5f;
	}
}
