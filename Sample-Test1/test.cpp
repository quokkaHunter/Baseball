﻿#include "pch.h"
#include "../BaseballKata/baseball.cpp"

class BaseballFixture : public testing::Test
{
public:
	Baseball baseball{ "123" };

	void assertIllegalArgument(string query)
	{
		try 
		{
			baseball.guess(query);
			FAIL();
		}
		catch (exception& e)
		{
			cout << e.what() << endl;
		}
	}
};

TEST_F(BaseballFixture, ThrowExceptionInvalidCase) {
	assertIllegalArgument("12");
	assertIllegalArgument("12s");
	assertIllegalArgument("121");
}
TEST_F(BaseballFixture, BaseballGameSolved) {
	baseball.setAnswer("123");
	GuessResults guessResults = baseball.guess("123");
	EXPECT_TRUE(guessResults.solved);
	EXPECT_EQ(3, guessResults.strikes);
	EXPECT_EQ(0, guessResults.balls);
}
