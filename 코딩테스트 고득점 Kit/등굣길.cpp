#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

const int MAX = 100 + 10;
const int MOD = 1000000007;

typedef struct
{
	int y, x;
} Puddle;

bool operator<(const Puddle a, const Puddle b)
{
	if (a.y < b.y)
	{
		return true;
	}

	if (a.y == b.y && a.x < b.x)
	{
		return true;
	}

	return false;
}

int cache[MAX][MAX];

int solution(int m, int n, vector<vector<int>> puddles) {
	set<Puddle> puddle;

	for (int i = 0; i < puddles.size(); i++)
	{
		puddle.insert({ puddles[i][1], puddles[i][0] });
	}

	cache[1][0] = 1;

	for (int y = 1; y <= n; y++) 
	{
		for (int x = 1; x <= m; x++) 
		{
			if (puddle.count({ y, x }))
			{
				cache[y][x] = 0;

				continue;
			}

			cache[y][x] = (cache[y - 1][x] + cache[y][x - 1]) % MOD;
		}
	}

	return cache[n][m];
}

int main(void)
{
	int m = 4;
	int n = 3;

	vector<vector<int>> puddles = { {2, 2} };

	cout << solution(m, n, puddles) << "\n";

	return 0;
}