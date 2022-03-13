#include <string>
#include <vector>
using namespace std;

bool isLower(char c)
{
	return c >= 'a' && c <= 'z';
}

bool isUpper(char c)
{
	return c >= 'A' && c <= 'Z';
}

string solution(string s) {
	string answer = "";
	bool upperTurn = true;

	for (char c : s)
	{
		if (c == ' ')
		{
			answer += c;
			upperTurn = true;

			continue;
		}

		if (upperTurn)
		{
			answer += isLower(c) ? (c - 'a') + 'A' : c;
		}
		else
		{
			answer += isUpper(c) ? c - 'A' + 'a' : c;
		}

		upperTurn = false;
	}

	return answer;
}