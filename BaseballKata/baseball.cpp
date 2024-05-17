#include <iostream>
#include <string>

using namespace std;

class Baseball
{
public:
	string guess(string query)
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

		string result = "";
		return result;
	}
};