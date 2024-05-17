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

		string result;
		return result;
	}
};