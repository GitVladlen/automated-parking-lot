#include <APL/Motorcycle.h>

namespace APL
{
	Motorcycle::Motorcycle(const std::string& _licensePlate, int _parkingDuration)
		: Vehicle(_licensePlate, VehicleType::Motorcycle, _parkingDuration)
	{
	}

	// Calculate the parking charge for a Motorcycle based on the parking duration
	float Motorcycle::calculateCharge() const
	{
		int parkingDuration = getParkingDuration();

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
