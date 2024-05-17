#include "pch.h"
#include "../BaseballKata/baseball.cpp"

TEST(TestCaseName, TestName) {
	Baseball baseball;
	EXPECT_THROW(baseball.guess("12"), length_error);
}