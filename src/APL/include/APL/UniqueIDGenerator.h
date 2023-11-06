#pragma once

#include <atomic>

namespace APL
{
	// UniqueIDGenerator class for generating unique IDs
	class UniqueIDGenerator {
	public:
		// Get the singleton instance of UniqueIDGenerator
		static UniqueIDGenerator& getInstance()
		{
			static UniqueIDGenerator instance; // Guaranteed to be created only once.
			return instance;
		}

		// Generate a unique ID atomically
		int generateUniqueID()
		{
			int id = m_counter.fetch_add(1);

			return id;
		}

	private:
		UniqueIDGenerator() = default; // Private constructor to prevent external instantiation.
		UniqueIDGenerator(const UniqueIDGenerator&) = delete; // Disable copy constructor.
		UniqueIDGenerator& operator=(const UniqueIDGenerator&) = delete; // Disable copy assignment.

		std::atomic<int> m_counter{ 1 }; // Atomic counter for generating unique IDs.
	};
}
