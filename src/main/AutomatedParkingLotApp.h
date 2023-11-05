#pragma once

#include <APL/ParkingLot.h>

namespace App
{
	class AutomatedParkingLotApp
	{
	public:
		AutomatedParkingLotApp();

		int run();

	private:
		APL::ParkingLot m_parkingLot;
	};
}