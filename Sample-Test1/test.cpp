#include "pch.h"
#include "../BaseballKata/baseball.cpp"

class BaseballFixture : public testing::Test
{
public:
	Baseball baseball;

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
