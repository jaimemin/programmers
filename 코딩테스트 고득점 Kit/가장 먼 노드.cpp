#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int MAX = 20000 + 200;

int longestDistance;
bool visited[MAX];
vector<int> nodes;
vector<int> graph[MAX];

typedef struct
{
	int idx;
	int distance;
} Node;

int solution(int n, vector<vector<int>> edge) {
	for (int i = 0; i < edge.size(); i++)
	{
		int u = edge[i][0];
		int v = edge[i][1];

		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	queue<Node> q;
	q.push({ 1, 0 });
	visited[1] = true;

	int longestDistance = 0;

	while (!q.empty())
	{
		Node cur = q.front();
		q.pop();

		if (cur.distance == longestDistance)
		{
			nodes.push_back(cur.idx);
		}

		if (cur.distance > longestDistance)
		{
			longestDistance = cur.distance;
		
			nodes.clear();
			nodes.push_back(cur.idx);
		}

		for (int i = 0; i < graph[cur.idx].size(); i++)
		{
			int next = graph[cur.idx][i];

			if (visited[next])
			{
				continue;
			}

			visited[next] = true;
			q.push({ next, cur.distance + 1 });
		}
	}

	return nodes.size();
}

int main(void)
{
	int n = 6;
	
	vector<vector<int>> edge = {
		{3, 6}, 
		{4, 3},
		{3, 2},
		{1, 3},
		{1, 2},
		{2, 4},
		{5, 2}
	};

	cout << solution(n, edge) << "\n";

	return 0;
}