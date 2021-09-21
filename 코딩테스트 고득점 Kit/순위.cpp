#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

const int MAX = 100 + 10;

vector<int> winners[MAX];
vector<int> losers[MAX];

int getWinnerCnt(int player)
{
	queue<int> q;
	q.push(player);

	bool visited[MAX] = { false, };
	visited[player] = true;

	int cnt = 0;

	while (!q.empty())
	{
		int cur = q.front();
		q.pop();

		cnt++;

		for (int winner : winners[cur])
		{
			if (visited[winner])
			{
				continue;
			}
			
			visited[winner] = true;
			q.push(winner);
		}
	}

	return cnt - 1;
}

int getLoserCnt(int player)
{
	queue<int> q;
	q.push(player);

	bool visited[MAX] = { false, };
	visited[player] = true;

	int cnt = 0;

	while (!q.empty())
	{
		int cur = q.front();
		q.pop();

		cnt++;

		for (int loser : losers[cur])
		{
			if (visited[loser])
			{
				continue;
			}

			visited[loser] = true;
			q.push(loser);
		}
	}

	return cnt - 1;
}

int solution(int n, vector<vector<int>> results) {
	int answer = 0;

	for (int i = 0; i < results.size(); i++)
	{
		int winner = results[i][0];
		int loser = results[i][1];

		winners[loser].push_back(winner);
		losers[winner].push_back(loser);
	}

	for (int player = 1; player <= n; player++)
	{
		int cnt = getWinnerCnt(player);
		cnt += getLoserCnt(player);

		if (cnt == n - 1)
		{
			answer++;
		}
	}

	return answer;
}

int main(void)
{
	int n = 5;
	vector<vector<int>> results = {
		{4, 3},
		{4, 2},
		{3, 2},
		{1, 2},
		{2, 5}
	};

	cout << solution(n, results) << "\n";

	return 0;
}