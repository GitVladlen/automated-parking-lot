#include <APL/UUIDGenerator.h>

namespace APL
{
	std::string UUIDGenerator::generateUniqueID() const
	{
		std::random_device rd;
		std::mt19937 gen(rd());
		std::uniform_int_distribution<> dis(0, 15);

		const char hex_chars[] = "0123456789ABCDEF";
		std::stringstream ss;

		for (int i = 0; i < 32; ++i) {
			if (i == 8 || i == 12 || i == 16 || i == 20) {
				ss << '-';
			}
			ss << hex_chars[dis(gen)];
		}

		return ss.str();
	}
}