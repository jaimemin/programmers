#include <iostream>
#include <string>
#include <vector>
using namespace std;

const int MOD = 1e7 + 19;
const int MAX = 300 + 30;

long long combinations[MAX][MAX];
long long cache[MAX][MAX];

void getCombinations(void)
{
	combinations[0][0] = 1;

	for (int i = 1; i < MAX; i++)
	{
		for (int j = 1; j < MAX;j++)
		{
			if (i == 0 || i == j)
			{
				combinations[i][j] = 1;

				continue;
			}

			combinations[i][j] = (combinations[i - 1][j - 1] + combinations[i - 1][j]) % MOD;
		}
	}
}

int solution(vector<vector<int>> a) {
	vector<int> ones;

	for (auto numbers : a)
	{
		int cnt = 0;

		for (int num : numbers)
		{
			if (num)
			{
				cnt++;
			}
		}

		ones.push_back(cnt);
	}

	for (int one : ones)
	{
		for(int )
	}
}