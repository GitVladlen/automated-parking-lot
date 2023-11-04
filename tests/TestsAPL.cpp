#include <gtest/gtest.h>

#include <APL/Utils.h>

TEST(TestCoreFunctionality, GenerateUniqueId)
{
	int uid1 = APL::Utils::UniqueIDGenerator::getInstance().generateUniqueID();
	int uid2 = APL::Utils::UniqueIDGenerator::getInstance().generateUniqueID();

	EXPECT_TRUE(uid1 != uid2);
}