#pragma once

#include <string>
#include <array>

namespace APL
{
	// Enumeration defining vehicle types
	enum class VehicleType
	{
		Car,
		Motorcycle,
		Bus,

		Count
	};

	// Function to convert VehicleType to a string
	inline std::string vehicleTypeToString(VehicleType _vehicleType)
	{
		// Static array that holds string representations of each VehicleType
		static const std::array<std::string, static_cast<int>(VehicleType::Count)> vehicleTypeStr = {
			"Car", "Motorcycle", "Bus"
		};

		// Return the string representation based on the index corresponding to the VehicleType
		return vehicleTypeStr[static_cast<int>(_vehicleType)];
	}
}
