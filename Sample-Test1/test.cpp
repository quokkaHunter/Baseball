#include "pch.h"
#include "../BaseballKata/baseball.cpp"

TEST(TestCaseName, BaseballGameWithInvalidArgumentLength) {
	Baseball baseball;
	EXPECT_THROW(baseball.guess("12"), length_error);
}

TEST(TestCaseName, BaseballGameWithInvalidArgumentType) {
	Baseball baseball;
	EXPECT_THROW(baseball.guess("12s"), invalid_argument);
}
