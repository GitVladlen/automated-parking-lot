#pragma once

#include <map>
#include <string>

namespace APL
{
	// Enumeration defining vehicle types
	enum class VehicleType
	{
		Car,
		Motorcycle,
		Bus
	};

	// Function to convert VehicleType to a string
	inline std::string vehicleTypeToString(VehicleType vehicleType)
	{
		// Map to associate VehicleType enum values with string representations
		static const std::map<VehicleType, std::string> vehicleTypeMap = {
			{VehicleType::Car, "Car"},
			{VehicleType::Motorcycle, "Motorcycle"},
			{VehicleType::Bus, "Bus"}
		};

		// Find the string representation for the given VehicleType
		auto it = vehicleTypeMap.find(vehicleType);
		if (it != vehicleTypeMap.end())
		{
			return it->second;
		}

		// Return "Unknown" if the VehicleType is not found in the map
		return "Unknown";
	}
}
