#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>
#include <iostream>
using namespace std;

const int INF = 987654321;

const int MAX = 4;

const int CARD_MAX = 6 + 1;

typedef struct
{
	int y, x, distance;
} State;

bool operator<(State a, State b)
{
	return a.distance > b.distance;
}

typedef struct
{
	int y, x;
} Dir;

Dir moveDir[4] = { { 1, 0 },{ -1, 0 },{ 0, 1 },{ 0, -1 } };

bool isCardAllFlipped(vector<vector<int>> &board)
{
	for (int y = 0; y < MAX; y++)
	{
		for (int x = 0; x < MAX; x++)
		{
			if (board[y][x])
			{
				return false;
			}
		}
	}

	return true;
}

bool isInRange(int y, int x)
{
	return y >= 0 && y < MAX && x >= 0 && x < MAX;
}

int getDistance(pair<int, int> src, pair<int, int> dest, vector<vector<int>> &board)
{
	priority_queue<State> pq;
	pq.push({ src.first, src.second, 0 });

	int dist[MAX][MAX];

	for (int y = 0; y < MAX; y++)
	{
		for (int x = 0; x < MAX; x++)
		{
			dist[y][x] = INF;
		}
	}

	dist[src.first][src.second] = true;

	while (!pq.empty())
	{
		State cur = pq.top();
		pq.pop();

		if (dist[cur.y][cur.x] < cur.distance)
		{
			continue;
		}

		if (cur.y == dest.first && cur.x == dest.second)
		{
			return cur.distance;
		}

		for (int k = 0; k < 4; k++)
		{
			int nextY = cur.y;
			int nextX = cur.x;
			int moveCnt = 0;

			while (isInRange(nextY + moveDir[k].y, nextX + moveDir[k].x))
			{
				nextY += moveDir[k].y;
				nextX += moveDir[k].x;
				moveCnt++;

				if (board[nextY][nextX])
				{
					break;
				}

				int nextDist = cur.distance + moveCnt;

				if (dist[nextY][nextX] > nextDist)
				{
					dist[nextY][nextX] = nextDist;

					pq.push({ nextY, nextX, nextDist });
				}
			}

			if (dist[nextY][nextX] > cur.distance + 1)
			{
				dist[nextY][nextX] = cur.distance + 1;

				pq.push({ nextY, nextX, cur.distance + 1 });
			}
		}
	}
}

int func(int r, int c, vector<vector<int>> &board)
{
	if (isCardAllFlipped(board))
	{
		return 0;
	}

	int answer = INT_MAX;

	for (int card = 1; card < CARD_MAX; card++)
	{
		vector<pair<int, int>> coords;

		for (int y = 0; y < MAX; y++)
		{
			for (int x = 0; x < MAX; x++)
			{
				if (board[y][x] == card)
				{
					coords.push_back({ y, x });
				}
			}
		}

		if (coords.empty())
		{
			continue;
		}

		int candidate = getDistance({ r, c }, coords[0], board)
			+ getDistance(coords[0], coords[1], board)
			+ 2;
		int candidate2 = getDistance({ r, c }, coords[1], board)
			+ getDistance(coords[1], coords[0], board)
			+ 2;

		board[coords[0].first][coords[0].second] = 0;
		board[coords[1].first][coords[1].second] = 0;

		candidate += func(coords[1].first, coords[1].second, board);
		candidate2 += func(coords[0].first, coords[0].second, board);

		answer = min({ answer, candidate, candidate2 });

		board[coords[0].first][coords[0].second] = card;
		board[coords[1].first][coords[1].second] = card;
	}

	return answer;
}

int solution(vector<vector<int>> board, int r, int c) {
	return func(r, c, board);
}

int main(void)
{
	int r = 1;
	int c = 0;
	vector<vector<int>> board = {
		{ 1,0,0,3 },
		{ 2,0,0,0 },
		{ 0,0,0,2 },
		{ 3,0,1,0 }
	};

	cout << solution(board, r, c) << "\n";

	return 0;
}