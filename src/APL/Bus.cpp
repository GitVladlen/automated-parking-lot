#include <APL/Bus.h>

namespace APL
{
	Bus::Bus(const std::string& _licensePlate, const Timestamp& _parkingTimestamp)
		: Vehicle(_licensePlate, VehicleType::Bus, _parkingTimestamp)
	{
	}

	float Bus::calculateCharge() const
	{
		int parkingDuration = calculateParkingDuration();

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