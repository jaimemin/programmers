#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int MAX = 25;

typedef struct
{
	int y, x;
} Dir;

Dir moveDir[4] = { { 1, 0 },{ -1, 0 },{ 0, 1 },{ 0, -1 } };

struct State
{
	int y, x;
	int cost;
	int prevDir;
	bool visited[MAX][MAX];

	State(int y, int x, int cost, int prevDir, bool visited[MAX][MAX]) : y(y), x(x), cost(cost), prevDir(prevDir)
	{
		for (int i = 0; i < MAX; i++)
		{
			for (int j = 0; j < MAX; j++)
			{
				this->visited[i][j] = visited[i][j];
			}
		}
	}
};

bool operator<(State a, State b)
{
	return a.cost > b.cost;
}

int solution(vector<vector<int>> board) {
	int answer = -1;
	int N = board.size();

	priority_queue<State> pq;
	bool visited[MAX][MAX] = { false, };
	visited[0][0] = true;
	pq.push({ 0, 0, 0, -1, visited });

	while (!pq.empty())
	{
		State cur = pq.top();
		int y = cur.y;
		int x = cur.x;
		int cost = cur.cost;
		int prevDir = cur.prevDir;
		pq.pop();

		if (y == N - 1 && x == N - 1)
		{
			return cost;
		}

		for (int k = 0; k < 4; k++)
		{
			int nextY = y + moveDir[k].y;
			int nextX = x + moveDir[k].x;

			if (nextY < 0 || nextY >= N || nextX < 0 || nextX >= N || board[nextY][nextX])
			{
				continue;
			}

			if (prevDir != -1 && cur.visited[nextY][nextX])
			{
				continue;
			}

			int nextCost = prevDir == -1 || prevDir == k ? cost + 100 : cost + 600;

			cur.visited[nextY][nextX] = true;
			pq.push({ nextY, nextX, nextCost, k, cur.visited });
		}
	}

	return answer;
}