#pragma once

#include <memory>

namespace APL
{
	// IUniqueIDGenerator interface for generating unique IDs
	class IUniqueIDGenerator
	{
	public:
		virtual ~IUniqueIDGenerator() = default;
		virtual std::string generateUniqueID() const = 0;
	};

	typedef std::shared_ptr<IUniqueIDGenerator> IUniqueIDGeneratorPtr;

	// Abstract class for creating IUniqueIDGenerator objects
	class IUniqueIDGeneratorFactory
	{
	public:
		// Pure virtual function to create a IUniqueIDGenerator object (to be implemented by derived classes)
		virtual IUniqueIDGeneratorPtr createGenerator() = 0;
	};

	// Define a shared pointer type for IUniqueIDGeneratorFactory objects
	typedef std::shared_ptr<IUniqueIDGeneratorFactory> IUniqueIDGeneratorFactoryPtr;
}
