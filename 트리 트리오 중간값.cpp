#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAX = 250000 + 2500;

int longestLen;
int furthestNode;
bool furthestNodeMoreThanOne;
vector<int> graph[MAX];
bool visited[MAX];

void func(int cur, int len)
{
	for (int node : graph[cur])
	{
		if (visited[node])
		{
			continue;
		}

		visited[node] = true;

		if (len + 1 > longestLen)
		{
			longestLen = len + 1;
			furthestNode = node;
			
			furthestNodeMoreThanOne = false;
		}
		else if (len + 1 == longestLen)
		{
			furthestNodeMoreThanOne = true;
		}

		func(node, len + 1);
	}
}

int solution(int n, vector<vector<int>> edges) {
	for (auto edge : edges)
	{
		int u = edge[0];
		int v = edge[1];

		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	// 1을 기준으로 제일 멀리 있는 노드 찾고
	visited[1] = true;
	func(1, 0);

	// 1에서 제일 멀리 있는 노드 기준으로 같은 거리에 있는 노드들이 있나 찾음
	memset(visited, false, sizeof(visited));
	visited[furthestNode] = true;
	longestLen = 0;
	func(furthestNode, longestLen);

	// 이 때, 거리가 제일 먼 노드가 둘 이상이라면 중간값은 longestLen
	if (furthestNodeMoreThanOne)
	{
		return longestLen;
	}

	// 거리가 제일 먼 노드가 하나라면 또 해당 노드를 기준으로 가장 먼 거리에 있는 노드들을 찾음
	memset(visited, false, sizeof(visited));
	visited[furthestNode] = true;
	longestLen = 0;
	func(furthestNode, longestLen);

	return furthestNodeMoreThanOne ? longestLen : longestLen - 1;
}

int main(void)
{
	int n = 4;
	vector<vector<int>> edges = {
		{ 1, 2 },
		{ 2, 3 },
		{ 3, 4 }
	};

	cout << solution(4, edges) << "\n";

	return 0;
}