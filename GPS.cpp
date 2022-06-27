#include <vector>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;

const int K_MAX = 100 + 10;

const int MAX = 200 + 20;

const int INF = 987654321;

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int n, int m, vector<vector<int>> edge_list, int k, vector<int> gps_log) {
	int edges[MAX][MAX] = { 0, };
	int cache[K_MAX][MAX];

	for (int i = 0; i < K_MAX; i++)
	{
		for (int j = 0; j < MAX; j++)
		{
			cache[i][j] = INF;
		}
	}

	for (vector<int> edge : edge_list)
	{
		int u = edge[0];
		int v = edge[1];

		edges[u][v] = 1;
		edges[v][u] = 1;
	}

	int firstGps = gps_log[0];
	int lastGps = gps_log[k - 1];

	cache[0][firstGps] = 0;

	for (int i = 1; i < k; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cache[i][j] = min(cache[i][j], cache[i - 1][j]);

			for (int k = 1; k <= n; k++)
			{
				if (edges[j][k] == 0)
				{
					continue;
				}

				cache[i][j] = min(cache[i][j], cache[i - 1][k]);
			}

			if (j != gps_log[i])
			{
				cache[i][j]++;
			}
		}
	}

	return cache[k - 1][lastGps] != INF ? cache[k - 1][lastGps] : -1;
}