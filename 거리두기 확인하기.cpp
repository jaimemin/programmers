#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 5;

typedef struct
{
	int y, x;
} Dir;

Dir moveDir[8] = { { 1, 1 },{ 1, 0 },{ 1, -1 },{ 0, -1 },{ -1, -1 },{ -1 , 0 },{ -1 , 1 },{ 0, 1 } };

int getDistance(pair<int, int> a, pair<int, int> b)
{
	return abs(a.first - b.first) + abs(a.second - b.second);
}

bool isDistancing(vector<pair<int, int>> v, vector<string> &place)
{
	for (int i = 0; i < v.size(); i++)
	{
		for (int j = i + 1; j < v.size(); j++)
		{
			if (getDistance(v[i], v[j]) > 2)
			{
				continue;
			}

			if (getDistance(v[i], v[j]) == 1)
			{
				return false;
			}

			// y 축으로 같은 열
			if (v[i].first == v[j].first)
			{
				int xMid = (v[i].second + v[j].second) / 2;

				if (place[v[i].first][xMid] == 'O')
				{
					return false;
				}
			}

			// x 축으로 같은 열
			if (v[i].second == v[j].second)
			{
				int yMid = (v[i].first + v[j].first) / 2;

				if (place[yMid][v[i].second] == 'O')
				{
					return false;
				}
			}

			// 대각선
			if (v[i].first != v[j].first
				&& v[i].second != v[j].second
				&& !(place[v[i].first][v[j].second] == 'X' && place[v[j].first][v[i].second] == 'X'))
			{
				return false;
			}
		}
	}

	return true;
}

vector<int> solution(vector<vector<string>> places) {
	vector<int> answer;

	for (vector<string> place : places)
	{
		bool flag = true;
		vector<pair<int, int>> v;

		for (int y = 0; y < place.size(); y++)
		{
			for (int x = 0; x < place[y].size(); x++)
			{
				if (place[y][x] == 'P')
				{
					v.push_back({ y, x });
				}
			}
		}

		answer.push_back(isDistancing(v, place));
	}

	return answer;
}