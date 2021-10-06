#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>
#include <cmath>
using namespace std;

const int INF = 987654321;
const int MAX = 100 + 10;

set<int> edges[MAX];

int getLength(int node, vector<vector<int>> &wires)
{
	int length = 0;
	queue<int> q;
	q.push(node);

	bool visited[MAX] = { false, };
	visited[node] = true;

	while (!q.empty())
	{
		int cur = q.front();
		q.pop();

		length++;

		for (auto next : edges[cur])
		{
			if (visited[next])
			{
				continue;
			}

			q.push(next);
			visited[next] = true;
		}
	}

	return length;
}

int solution(int n, vector<vector<int>> wires) {
	for (auto wire : wires)
	{
		edges[wire[0]].insert(wire[1]);
		edges[wire[1]].insert(wire[0]);
	}

	int answer = INF;

	for (auto wire : wires)
	{
		edges[wire[0]].erase(wire[1]);
		edges[wire[1]].erase(wire[0]);
		
		answer = min(answer, abs(getLength(wire[0], wires) - getLength(wire[1], wires)));

		edges[wire[0]].insert(wire[1]);
		edges[wire[1]].insert(wire[0]);
	}

	return answer;
}