#pragma once

#include <string>
#include <sstream>
#include <random>

#include <APL/IUniqueIDGenerator.h>

namespace APL
{
	// UUIDGenerator class for generating unique IDs
	class UUIDGenerator : public IUniqueIDGenerator
	{
	public:
		// Generate a unique ID using random numbers
		virtual std::string generateUniqueID() const override;
	};

	class UUIDGeneratorFactory : public IUniqueIDGeneratorFactory
	{
	public:
		// Create a UUIDGeneratorFactory instance
		IUniqueIDGeneratorPtr createGenerator() override
		{
			return std::make_shared<UUIDGenerator>();
		}
	};
}