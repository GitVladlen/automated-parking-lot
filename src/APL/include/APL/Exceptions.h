#pragma once

#include <exception>
#include <string>

namespace APL
{
	class BaseMessageException : public std::exception {
	public:
		BaseMessageException(const std::string& _message)
			: m_message(_message)
		{
		}

		const char* what() const noexcept override
		{
			return m_message.c_str();
		}

	private:
		std::string m_message;
	};

	class NegativeCapacityException : public BaseMessageException
	{
	public:
		NegativeCapacityException(VehicleType _vechicleType, int _capacity)
			: BaseMessageException("Negative capacity " + std::to_string(_capacity) + " for " + vehicleTypeToString(_vechicleType))
		{
		}
	};

	class InvalidVehicleTypeException : BaseMessageException
	{
	public:
		InvalidVehicleTypeException(VehicleType _vehicleType)
			: BaseMessageException("Invalid vehicle type: " + vehicleTypeToString(_vehicleType))
		{
		}
	};

	class InvalidTicketIDException : public BaseMessageException
	{
	public:
		InvalidTicketIDException(int _ticket)
			: BaseMessageException("Invalid ticket ID: " + _ticket)
		{
		}
	};
}