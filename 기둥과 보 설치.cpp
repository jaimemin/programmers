#include <string>
#include <vector>
#include <set>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 100 + 1;

bool visited[MAX][MAX][2]; // 0: ±âµÕ, 1: º¸

struct State
{
	int y, x, a;
};

bool operator<(State a, State b)
{
	return a.y != b.y ? a.y < b.y : (a.x != b.x ? a.x < b.x : a.a < b.a);
}

bool cmp(State a, State b)
{
	if (a.y == b.y)
	{
		if (a.x == b.x)
		{
			return a.a < b.a;
		}

		return a.x < b.x;
	}

	return a.y < b.y;
}

set<State> s;

bool canBeInstalled(int y, int x, int a, int n)
{
	if (visited[y + 1][x][0])
	{
		return true;
	}

	if (a == 0)
	{
		if (y == n)
		{
			return true;
		}

		if (visited[y][x][1])
		{
			return true;
		}

		if (x >= 1 && visited[y][x - 1][1])
		{
			return true;
		}
	}
	else
	{
		if (visited[y][x - 1][1] && visited[y][x + 1][1])
		{
			return true;
		}

		if (x + 1 <= n && visited[y + 1][x + 1][0])
		{
			return true;
		}
	}

	return false;
}

bool canBeDeleted(int y, int x, int a, int n)
{
	visited[y][x][a] = false;

	for (auto state : s)
	{
		if (y == state.y && x == state.x && a == state.a)
		{
			continue;
		}

		if (!canBeInstalled(state.y, state.x, state.a, n))
		{
			visited[y][x][a] = true;

			return false;
		}
	}

	return true;
}

vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
	for (vector<int> frame : build_frame)
	{
		int y = n - frame[1];
		int x = frame[0];
		int a = frame[2];
		int b = frame[3];

		if (b == 1)
		{
			if (canBeInstalled(y, x, a, n))
			{
				s.insert({ y, x, a });

				visited[y][x][a] = true;
			}
		}
		else
		{
			if (canBeDeleted(y, x, a, n))
			{
				s.erase({ y, x, a });
			}
		}
	}

	vector<vector<int>> answer;

	for (auto state : s)
	{
		vector<int> v{ state.x, n - state.y, state.a };

		answer.push_back(v);
	}

	sort(answer.begin(), answer.end());

	return answer;
}