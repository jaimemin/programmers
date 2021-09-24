#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 100 + 10;

typedef struct
{
	int idx;
	int cost;
} Edge;

bool cmp(Edge a, Edge b)
{
	return a.cost < b.cost;
}

int parent[MAX];

int getParent(int node)
{
	if (parent[node] == node)
	{
		return node;
	}

	return parent[node] = getParent(parent[node]);
}

int solution(int n, vector<vector<int>> costs) {
	vector<Edge> edges;

	for (int i = 0; i < costs.size(); i++)
	{
		int u = costs[i][0];
		int v = costs[i][1];
		int cost = costs[i][2];

		edges.push_back({ i, cost });
	}

	sort(edges.begin(), edges.end(), cmp);

	for (int i = 0; i < n; i++)
	{
		parent[i] = i;
	}

	int answer = 0;

	for (Edge edge : edges)
	{
		int u = getParent(parent[costs[edge.idx][0]]);
		int v = getParent(parent[costs[edge.idx][1]]);
		int cost = costs[edge.idx][2];

		if (u != v)
		{
			answer += cost;
			parent[v] = u;
		}
	}

	return answer;
}

int main(void)
{
	int n = 4;
	vector<vector<int>> costs = {
		{0, 1, 1},
		{0, 2, 2},
		{1, 2, 5},
		{1, 3, 1},
		{2, 3, 8}
	};

	cout << solution(n, costs) << "\n";

	return 0;
}