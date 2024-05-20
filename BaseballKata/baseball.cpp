#include <iostream>
#include <string>

using namespace std;

struct GuessResults
{
	bool solved;
	int strikes;
	int balls;
};

class Baseball
{
public:
	Baseball(string answer) { this->answer = answer; }

	GuessResults& guess(string query)
	{
		assertIllegalArgument(query);

		GuessResults guessResults = {};

		checkStrike(query, guessResults);
		checkBall(query, guessResults);
		checkSolved(guessResults);

		return guessResults;
	}

	void checkSolved(GuessResults& guessResults)
	{
		if (guessResults.strikes == 3)
			guessResults.solved = true;
	}

	void checkBall(std::string& query, GuessResults& guessResults)
	{
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (i == j) continue;

				if (query[i] == answer[j])
					guessResults.balls++;
			}
		}
	}

	void checkStrike(std::string& query, GuessResults& guessResults)
	{
		for (int i = 0; i < 3; i++)
		{
			if (query[i] == answer[i])
				guessResults.strikes++;
		}
	}

	void assertIllegalArgument(std::string& query)
	{
		if (query.length() != 3)
		{
			throw length_error("Length Error! Query Length should be 3");
		}
		for (char ch : query)
		{
			if (isdigit(ch) == 0)
				throw invalid_argument("Query should be consist of number");
		}
		if (isOverlappedNumber(query))
			throw invalid_argument("Must not have same number in Query");
	}
	bool isOverlappedNumber(std::string& query)
	{
		return query[0] == query[1] || query[1] == query[2] || query[0] == query[2];
	}
private:
	string answer;
};