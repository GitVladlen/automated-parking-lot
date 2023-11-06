#include <APL/Bus.h>

namespace APL
{
	Bus::Bus(const std::string& _licensePlate, int _parkingDuration)
		: Vehicle(_licensePlate, VehicleType::Bus, _parkingDuration)
	{
	}

	// Calculate the parking charge for a Bus based on the parking duration
	float Bus::calculateCharge() const
	{
		int parkingDuration = getParkingDuration();

		if (parkingDuration <= 1)
		{
			return 5.0f;
		}
		else
		{
			return 5.0f + (parkingDuration - 1) * 3.0f;
		}
	}
}
