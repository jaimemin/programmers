#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

const int INF = 987654321;
const int MAX = 20000 + 1;

int cache[MAX];

void init(void)
{
	for (int i = 1; i < MAX; i++)
	{
		cache[i] = INF;
	}
}

int solution(vector<string> strs, string t)
{
	init();

	for (int len = 1; len <= t.length(); len++)
	{
		for (string str : strs)
		{
			int startIdx = len - str.length();

			if (startIdx < 0)
			{
				continue;
			}

			bool allSame = true;

			for (int i = 0; i < str.length(); i++)
			{
				if (t[startIdx + i] != str[i])
				{
					allSame = false;

					break;
				}
			}

			if (allSame == false)
			{
				continue;
			}

			cache[len] = min(cache[len], cache[startIdx] + 1);
		}
	}

	return cache[t.length()] == INF ? -1 : cache[t.length()];
}

int main(void)
{
	vector<string> strs = { "ba", "na", "n", "a" };
	string t = "banana";

	cout << solution(strs, t) << "\n";

	return 0;
}