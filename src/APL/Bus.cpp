#include <APL/Bus.h>

namespace APL
{
	Bus::Bus(const std::string& _licensePlate, int _parkingDuration)
		: Vehicle(_licensePlate, VehicleType::Bus, _parkingDuration)
	{
	}

	float Bus::getBaseCharge() const
	{
		return 5.0f;
	}

	float Bus::getAdditionalChargePerHour() const
	{
		return 3.0f;
	}
}
