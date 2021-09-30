#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
using namespace std;

const int MAX = 300000 + 300;

long long result;
bool visited[MAX];
vector<long long> weights;
vector<int> connected[MAX];

long long func(int node)
{
	visited[node] = true;

	for (int next : connected[node])
	{
		if (visited[next])
		{
			continue;
		}

		weights[node] += func(next);
	}

	result += abs(weights[node]);

	return weights[node];
}

long long solution(vector<int> a, vector<vector<int>> edges) {
	long long sum = 0;

	for (int num : a)
	{
		sum += num;

		weights.push_back(num);
	}

	if (sum)
	{
		return -1;
	}

	for (auto edge : edges)
	{
		connected[edge[0]].push_back(edge[1]);
		connected[edge[1]].push_back(edge[0]);
	}
	
	func(0);

	return result;
}

int main(void)
{
	vector<int> a = { -5, 0, 2, 1, 2 };
	vector<vector<int>> edges = {
		{0, 1},
		{3, 4},
		{2, 3},
		{0, 3}
	};

	cout << solution(a, edges) << "\n";

	return 0;
}