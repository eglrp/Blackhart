#include <gtest\gtest.h>

int main(int argc, char** argv)
{
	testing::InitGoogleTest(&argc, argv);
	int lTestResult = RUN_ALL_TESTS();
	std::getchar();
	return lTestResult;
}