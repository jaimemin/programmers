#include <string>
#include <vector>

using namespace std;

string solution(string s) {
	string answer = "";
	int idx = 0;

	for (char c : s)
	{
		if (c == ' ')
		{
			answer += c;
			idx = 0;

			continue;
		}

		answer += idx++ % 2 ? tolower(c) : toupper(c);
	}

	return answer;
}