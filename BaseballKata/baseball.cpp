#include <iostream>
#include <string>

using namespace std;

class Baseball
{
public:
	string guess(string query)
	{
		assertIllegalArgument(query);

		string result = "";
		return result;
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