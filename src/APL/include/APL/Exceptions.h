#pragma once

#include <exception>
#include <string>

#include <APL/Vehicle.h>

namespace APL
{
	// Base exception class that inherits from std::exception
	class BaseMessageException : public std::exception
	{
	public:
		// Constructor that accepts a message
		BaseMessageException(const std::string& _message)
			: m_message(_message)
		{
		}

		// Override the what() function to provide the exception message
		const char* what() const noexcept override
		{
			return m_message.c_str();
		}

	private:
		std::string m_message;
	};

	// Custom exception for a negative capacity
	class NegativeCapacityException : public BaseMessageException
	{
	public:
		// Constructor that generates a message based on vehicle type and capacity
		NegativeCapacityException(VehicleType _vehicleType, int _capacity)
			: BaseMessageException("Negative capacity " + std::to_string(_capacity) + " for " + vehicleTypeToString(_vehicleType))
		{
		}
	};

	// Custom exception for an invalid vehicle type
	class InvalidVehicleTypeException : public BaseMessageException
	{
	public:
		// Constructor that generates a message based on an invalid vehicle type
		InvalidVehicleTypeException(VehicleType _vehicleType)
			: BaseMessageException("Invalid vehicle type: " + vehicleTypeToString(_vehicleType))
		{
		}
	};

	// Custom exception for running out of vehicle capacity
	class OutOfVehicleCapacityException : public BaseMessageException
	{
	public:
		// Constructor that generates a message based on a specific vehicle type
		OutOfVehicleCapacityException(VehicleType _vehicleType)
			: BaseMessageException("Out of capacity for vehicle type: " + vehicleTypeToString(_vehicleType))
		{
		}
	};

	// Custom exception for an invalid ticket ID
	class InvalidTicketIDException : public BaseMessageException
	{
	public:
		// Constructor that generates a message based on an invalid ticket ID
		InvalidTicketIDException(const std::string& _ticket)
			: BaseMessageException("Invalid ticket ID: " + _ticket)
		{
		}
	};
}
