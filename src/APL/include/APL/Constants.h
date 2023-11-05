#pragma once

#include <map>
#include <string>

namespace APL
{
	enum class VehicleType
	{
		Car,
		Motorcycle,
		Bus
	};

    // Function to convert VehicleType to a string
    inline std::string vehicleTypeToString(VehicleType vehicleType)
    {
        static const std::map<VehicleType, std::string> vehicleTypeMap = {
            {VehicleType::Car, "Car"},
            {VehicleType::Motorcycle, "Motorcycle"},
            {VehicleType::Bus, "Bus"}
        };

        auto it = vehicleTypeMap.find(vehicleType);
        if (it != vehicleTypeMap.end())
        {
            return it->second;
        }
        return "Unknown";
    }
}