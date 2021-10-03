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

	// 1�� �������� ���� �ָ� �ִ� ��� ã��
	visited[1] = true;
	func(1, 0);

	// 1���� ���� �ָ� �ִ� ��� �������� ���� �Ÿ��� �ִ� ������ �ֳ� ã��
	memset(visited, false, sizeof(visited));
	visited[furthestNode] = true;
	longestLen = 0;
	func(furthestNode, longestLen);

	// �� ��, �Ÿ��� ���� �� ��尡 �� �̻��̶�� �߰����� longestLen
	if (furthestNodeMoreThanOne)
	{
		return longestLen;
	}

	// �Ÿ��� ���� �� ��尡 �ϳ���� �� �ش� ��带 �������� ���� �� �Ÿ��� �ִ� ������ ã��
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