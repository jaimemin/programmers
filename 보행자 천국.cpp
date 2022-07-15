#include <vector>
#include <cstring>
using namespace std;

const int MOD = 20170805;

const int MAX = 500 + 1;

int cache[MAX][MAX][2];

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int m, int n, vector<vector<int>> city_map) {
	memset(cache, 0, sizeof(cache));
	cache[1][1][0] = 1;
	cache[1][1][1] = 1;

	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			switch (city_map[i - 1][j - 1])
			{
			case 0:
				cache[i][j][0] = (cache[i][j][0] + cache[i - 1][j][0] + cache[i][j - 1][1]) % MOD;
				cache[i][j][1] = (cache[i][j][1] + cache[i - 1][j][0] + cache[i][j - 1][1]) % MOD;

				break;
			case 1:
				cache[i][j][0] = 0;
				cache[i][j][1] = 0;

				break;
			case 2:
				cache[i][j][0] = cache[i - 1][j][0] % MOD;
				cache[i][j][1] = cache[i][j - 1][1] % MOD;

				break;
			}
		}
	}

	return cache[m][n][0] % MOD;
}