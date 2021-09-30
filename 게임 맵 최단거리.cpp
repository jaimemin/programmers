#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int MAX = 100;

typedef struct
{
	int y, x, cnt;
} Player;

typedef struct
{
	int y, x;
} Dir;

Dir moveDir[4] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };

int solution(vector<vector<int> > maps)
{
	bool visited[MAX][MAX] = { false, };

	queue<Player> q;
	q.push({ 0, 0, 0 });
	visited[0][0] = true;
	
	int row = maps.size();
	int col = maps[0].size();

	while (!q.empty())
	{
		int y = q.front().y;
		int x = q.front().x;
		int cnt = q.front().cnt;
		q.pop();

		if (y == row - 1 && x == col - 1)
		{
			return cnt + 1;
		}

		for (int k = 0; k < 4; k++)
		{
			int nextY = y + moveDir[k].y;
			int nextX = x + moveDir[k].x;

			if (nextY < 0 || nextY >= row || nextX < 0 || nextX >= col)
			{
				continue;
			}

			if (maps[nextY][nextX] == 0 || visited[nextY][nextX])
			{
				continue;
			}

			visited[nextY][nextX] = true;
			q.push({ nextY, nextX, cnt + 1 });
		}
	}

	return -1;
}