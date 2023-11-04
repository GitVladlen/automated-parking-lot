#include <APL/Vehicle.h>

namespace APL
{
	Vehicle::Vehicle(const std::string& _licensePlate, VehicleType _vehicleType, const Timestamp& _parkingTimestamp)
		: m_licensePlate(_licensePlate)
		, m_vehicleType(_vehicleType)
		, m_parkingTimestamp(_parkingTimestamp)
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

	const Timestamp& Vehicle::getParkingTimestamp() const
	{
		return m_parkingTimestamp;
	}

	int Vehicle::calculateParkingDuration() const
	{
		auto now = std::chrono::system_clock::now();
		auto duration = now - m_parkingTimestamp;
		return std::chrono::duration_cast<std::chrono::hours>(duration).count();
	}
}