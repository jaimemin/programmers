#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int MAX = 200 + 20;

const int INF = 2e6 + 2e3;

vector<pair<int, int>> edges[MAX];

int dijkstra(int start, int end)
{
	vector<int> distance(MAX, INF);
	distance[start] = 0;

	priority_queue<pair<int, int>> pq;
	pq.push({ 0, start });

	while (!pq.empty())
	{
		int cost = -pq.top().first;
		int curVertex = pq.top().second;
		pq.pop();

		if (distance[curVertex] < cost)
		{
			continue;
		}

		for (pair<int, int> vertex : edges[curVertex])
		{
			int neighbor = vertex.first;
			int neighborDistance = cost + vertex.second;

			if (distance[neighbor] > neighborDistance)
			{
				distance[neighbor] = neighborDistance;

				pq.push({ -neighborDistance, neighbor });
			}
		}
	}

	return distance[end];
}

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
	for (vector<int> fare : fares)
	{
		int u = fare[0];
		int v = fare[1];
		int cost = fare[2];

		edges[u].push_back({ v, cost });
		edges[v].push_back({ u, cost });
	}

	int answer = dijkstra(s, a) + dijkstra(s, b);

	for (int i = 1; i <= n; i++)
	{
		if (s == i)
		{
			continue;
		}

		answer = min(answer, dijkstra(s, i) + dijkstra(i, a) + dijkstra(i, b));
	}

	return answer;
}