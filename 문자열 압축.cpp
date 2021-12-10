#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string result;

void func(int idx, int len, string before, int cnt, string word, string &s)
{
	if (idx >= s.length())
	{
		word += (cnt >= 2 ? to_string(cnt) : "") + before;

		if (result == "" || result.length() > word.length())
		{
			result = word;
		}

		return;
	}

	string next = s.substr(idx, len);

	if (before == next)
	{
		func(idx + len, len, before, cnt + 1, word, s);
	}
	else
	{
		func(idx + len, len, next, 1, word + (cnt >= 2 ? to_string(cnt) : "") + before, s);
	}
}

int solution(string s) {
	if (s.length() == 1)
	{
		return 1;
	}

	for (int len = 1; len <= s.length() / 2; len++)
	{
		string before = s.substr(0, len);

		func(len, len, before, 1, "", s);
	}

	return result.length();
}