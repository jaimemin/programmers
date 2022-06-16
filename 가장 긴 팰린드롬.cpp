#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAX = 2500 + 25;

int cache[MAX][MAX];

int solution(string s)
{
	int answer = 1;

	for (int i = 0; i < s.length(); i++)
	{
		cache[i][i] = 1;
	}

	for (int i = 0; i < s.length() - 1; i++)
	{
		if (s[i] == s[i + 1])
		{
			cache[i][i + 1] = 1;

			answer = 2;
		}
	}

	for (int i = 3; i <= s.length(); i++)
	{
		for (int j = 0; j <= s.length() - i; j++)
		{
			if (s[j] == s[i + j - 1] && cache[j + 1][i + j - 2] == 1)
			{
				cache[j][i + j - 1] = 1;

				answer = max(answer, i);
			}
		}
	}

	return answer;
}