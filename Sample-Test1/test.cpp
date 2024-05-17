#include "pch.h"
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
	GuessResults guessResults = baseball.guess("123");
	EXPECT_TRUE(guessResults.solved);
	EXPECT_EQ(3, guessResults.strikes);
	EXPECT_EQ(0, guessResults.balls);
}
TEST_F(BaseballFixture, BaseballGameTwoStrikeZeroBall) {
	GuessResults guessResults = baseball.guess("143");
	EXPECT_EQ(2, guessResults.strikes);
	EXPECT_EQ(0, guessResults.balls);
}
TEST_F(BaseballFixture, BaseballGameOneStrikeTwoBall) {
	GuessResults guessResults = baseball.guess("213");
	EXPECT_EQ(1, guessResults.strikes);
	EXPECT_EQ(2, guessResults.balls);
}
TEST_F(BaseballFixture, BaseballGameZeroStrikeThreeBall) {
	GuessResults guessResults = baseball.guess("312");
	EXPECT_EQ(0, guessResults.strikes);
	EXPECT_EQ(3, guessResults.balls);
}
TEST_F(BaseballFixture, BaseballGameZeroStrikeTwoBall) {
	GuessResults guessResults = baseball.guess("342");
	EXPECT_EQ(0, guessResults.strikes);
	EXPECT_EQ(2, guessResults.balls);
}
TEST_F(BaseballFixture, BaseballGameZeroStrikeZeroBall) {
	GuessResults guessResults = baseball.guess("456");
	EXPECT_EQ(0, guessResults.strikes);
	EXPECT_EQ(0, guessResults.balls);
}
