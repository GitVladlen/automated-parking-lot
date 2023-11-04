#include <iostream>
#include <chrono>
#include <atomic>
#include <thread>
#include <vector>
#include <mutex>

namespace APL
{
	namespace Utils
	{
        class UniqueIDGenerator {
        public:
            static UniqueIDGenerator& getInstance() {
                static UniqueIDGenerator instance; // Guaranteed to be created only once.
                return instance;
            }

            int generateUniqueID() {
                auto current_time = std::chrono::high_resolution_clock::now();
                auto timestamp = std::chrono::duration_cast<std::chrono::milliseconds>(current_time.time_since_epoch()).count();

                int id = static_cast<int>(timestamp) * 1000 + counter_.fetch_add(1);

                return id;
            }

        private:
            UniqueIDGenerator() = default; // Private constructor to prevent external instantiation.
            UniqueIDGenerator(const UniqueIDGenerator&) = delete; // Disable copy constructor.
            UniqueIDGenerator& operator=(const UniqueIDGenerator&) = delete; // Disable copy assignment.

            std::atomic<int> counter_{ 0 };
        };
	}
}