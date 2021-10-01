#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int MAX = 300;

typedef struct
{
	int y, x;
} Dir;

Dir moveDir[4] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };

typedef struct
{
	int groupA;
	int groupB;
	int cost;
} Edge;

bool cmp(Edge a, Edge b)
{
	return a.cost < b.cost;
}

vector<int> parents;
vector<Edge> edges;
bool visited[MAX][MAX];
int groups[MAX][MAX];

int findParent(int u)
{
	if (parents[u] == u)
	{
		return u;
	}

	return parents[u] = findParent(parents[u]);
}

int solution(vector<vector<int>> land, int height) {
	int group = 1;

	// 그룹핑
	for (int i = 0; i < land.size(); i++)
	{
		for (int j = 0; j < land.size(); j++)
		{
			if (visited[i][j])
			{
				continue;
			}

			queue<pair<int, int>> q;
			q.push({ i, j });
			visited[i][j] = true;
			groups[i][j] = group;

			while (!q.empty())
			{
				int y = q.front().first;
				int x = q.front().second;
				q.pop();

				for (int k = 0; k < 4; k++)
				{
					int nextY = y + moveDir[k].y;
					int nextX = x + moveDir[k].x;

					if (nextY < 0 || nextY >= land.size() || nextX < 0 || nextX >= land.size())
					{
						continue;
					}

					if (visited[nextY][nextX] || abs(land[y][x] - land[nextY][nextX]) > height)
					{
						continue;
					}

					visited[nextY][nextX] = true;
					groups[nextY][nextX] = group;
					q.push({ nextY, nextX });
				}
			}

			group++;
		}
	}

	parents.resize(group);

	for (int i = 1; i < group; i++)
	{
		parents[i] = i;
	}

	// 그룹 간 거리 구함
	for (int y = 0; y < land.size(); y++)
	{
		for (int x = 0; x < land.size(); x++)
		{
			for (int k = 0; k < 4; k++)
			{
				int nextY = y + moveDir[k].y;
				int nextX = x + moveDir[k].x;

				if (nextY < 0 || nextY >= land.size() || nextX < 0 || nextX >= land.size())
				{
					continue;
				}

				if (groups[y][x] == groups[nextY][nextX])
				{
					continue;
				}

				edges.push_back({ groups[y][x], groups[nextY][nextX], abs(land[y][x] - land[nextY][nextX]) });
			}
		}
	}

	sort(edges.begin(), edges.end(), cmp);

	int answer = 0;

	for (Edge edge : edges)
	{
		int groupA = findParent(edge.groupA);
		int groupB = findParent(edge.groupB);
		int cost = edge.cost;

		if (groupA == groupB)
		{
			continue;
		}

		parents[groupB] = groupA;
		answer += cost;
	}

	return answer;
}

int main(void)
{
	vector<vector<int>> land = {
		{ 1, 4, 8, 10 },
		{ 5, 5, 5, 5 },
		{ 10, 10, 10, 10 },
		{ 10, 10, 10, 20 }
	};
	int height = 3;

	cout << solution(land, height) << "\n";

	return 0;
}