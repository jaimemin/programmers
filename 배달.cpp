#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;

const int MAX = 50 + 5;
const int INF = 987654321;

typedef struct
{
	int idx;
	int cost;
} Node;

bool operator<(Node a, Node b)
{
	return a.cost > b.cost;
}

vector<int> graph[MAX];
int costs[MAX][MAX];
int distances[MAX];

int solution(int N, vector<vector<int> > road, int K) {
	for (int i = 0; i < MAX; i++)
	{
		for (int j = 0; j < MAX; j++)
		{
			costs[i][j] = INF;
		}

		distances[i] = INF;
	}

	map<pair<int, int>, bool> visited;

	for (auto node : road)
	{
		costs[node[0]][node[1]] = min(costs[node[0]][node[1]], node[2]);
		costs[node[1]][node[0]] = min(costs[node[1]][node[0]], node[2]);

		if (visited.count({ node[0], node[1] }))
		{
			continue;
		}
		
		visited[{node[0], node[1]}] = true;
		graph[node[0]].push_back(node[1]);
		graph[node[1]].push_back(node[0]);
	}

	priority_queue<Node> pq;
	pq.push({ 1, 0 });
	distances[1] = 0;

	while (!pq.empty())
	{
		int cur = pq.top().idx;
		int cost = pq.top().cost;
		pq.pop();

		for (int next : graph[cur])
		{
			int nextCost = distances[cur] + costs[cur][next];

			if (distances[next] > nextCost)
			{
				distances[next] = nextCost;
				pq.push({ next, nextCost });
			}
		}
	}

	int answer = 0;

	for (int i = 1; i <= N; i++)
	{
		if (distances[i] <= K)
		{
			answer++;
		}
	}

	return answer;
}