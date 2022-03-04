#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;

const int COL_MAX = 1e5;

const int ROW_MAX = 4;

int cache[COL_MAX][ROW_MAX];

int getMaxScore(int y, int x, vector<vector<int>> &land)
{
	if (y == land.size())
	{
		return 0;
	}

	int &result = cache[y][x];

	if (result != -1)
	{
		return result;
	}

	result = land[y][x];
	int temp = 0;

	for (int nextX = 0; nextX < ROW_MAX; nextX++)
	{
		if (nextX == x)
		{
			continue;
		}

		temp = max(temp, getMaxScore(y + 1, nextX, land));
	}

	result += temp;

	return result;
}

int solution(vector<vector<int> > land)
{
	memset(cache, -1, sizeof(cache));

	int answer = 0;

	for (int i = 0; i < ROW_MAX; i++)
	{
		answer = max(answer, getMaxScore(0, i, land));
	}

	return answer;
}