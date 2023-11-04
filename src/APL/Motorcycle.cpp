#include <APL/Motorcycle.h>

namespace APL
{
	Motorcycle::Motorcycle(const std::string& _licensePlate, const Timestamp& _parkingTimestamp)
		: Vehicle(_licensePlate, VehicleType::Motorcycle, _parkingTimestamp)
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