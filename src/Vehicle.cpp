#include "Vehicle.h"

namespace APL
{
	Vehicle::Vehicle(const std::string& _licensePlate, VehicleType _vehicleType)
		: m_licensePlate(_licensePlate)
		, m_vehicleType(_vehicleType)
		, m_parkingTimestamp()
	{
	}

	Vehicle::~Vehicle()
	{
	}

	const std::string& Vehicle::getLicensePlate() const
	{
		return m_licensePlate;
	}

	VehicleType Vehicle::getVehicleType() const
	{
		return m_vehicleType;
	}

	void Vehicle::updateParkingTimestamp()
	{
		m_parkingTimestamp = std::chrono::system_clock::now();
	}

	int Vehicle::calculateParkingDuration() const
	{
		auto now = std::chrono::system_clock::now();
		auto duration = now - m_parkingTimestamp;
		return std::chrono::duration_cast<std::chrono::hours>(duration).count();
	}
}