#include <string>
#include <vector>
#include <map>
using namespace std;

map<string, string> string2int;

void init(void)
{
	string2int["zero"] = "0";
	string2int["one"] = "1";
	string2int["two"] = "2";
	string2int["three"] = "3";
	string2int["four"] = "4";
	string2int["five"] = "5";
	string2int["six"] = "6";
	string2int["seven"] = "7";
	string2int["eight"] = "8";
	string2int["nine"] = "9";
}

int solution(string s) {
	init();

	string temp, result;

	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] >= '0' && s[i] <= '9')
		{
			result += s[i];

			continue;
		}

		temp += s[i];

		if (!temp.empty()
			&& string2int.count(temp))
		{
			result += string2int[temp];

			temp = "";
		}
	}

	if (!temp.empty()
		&& string2int.count(temp))
	{
		result += string2int[temp];
	}

	return stoi(result);
}