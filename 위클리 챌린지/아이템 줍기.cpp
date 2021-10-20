#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

const int MAX = 100 + 10;

typedef struct
{
	int y, x, cnt;
} Status;

typedef struct
{
	int y, x;
} Dir;

Dir moveDir[4] = { { 1, 0 },{ -1, 0 },{ 0, 1 },{ 0, -1 } };

bool parameter[MAX][MAX][4]; // y, x, dir
bool visited[MAX][MAX];

int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
	// 각 직사각형 테두리
	for (auto r : rectangle)
	{
		// 가로
		for (int x = r[0] * 2; x <= r[2] * 2; x++)
		{
			parameter[r[1] * 2][x][2] = true;
			parameter[r[3] * 2][x][2] = true;
			parameter[r[1] * 2][x][3] = true;
			parameter[r[3] * 2][x][3] = true;
		}

		// 세로
		for (int y = r[1] * 2; y <= r[3] * 2; y++)
		{
			parameter[y][r[0] * 2][0] = true;
			parameter[y][r[2] * 2][0] = true;
			parameter[y][r[0] * 2][1] = true;
			parameter[y][r[2] * 2][1] = true;
		}
	}

	// 각 직사각형 내부 visited 해제
	for (auto r : rectangle)
	{
		for (int y = r[1] * 2 + 1; y < r[3] * 2; y++)
		{
			for (int x = r[0] * 2 + 1; x < r[2] * 2; x++)
			{
				for (int k = 0; k < 4; k++)
				{
					parameter[y][x][k] = false;
				}
			}
		}
	}

	queue<Status> q;
	q.push({ characterY * 2, characterX * 2, 0 });
	visited[characterY * 2][characterX * 2] = true;

	while (!q.empty())
	{
		int curY = q.front().y;
		int curX = q.front().x;
		int cnt = q.front().cnt;
		q.pop();

		if (curY == itemY * 2 && curX == itemX * 2)
		{
			return cnt / 2;
		}

		for (int k = 0; k < 4; k++)
		{
			int nextY = curY + moveDir[k].y;
			int nextX = curX + moveDir[k].x;

			if (nextY < 2 || nextY > 100 || nextX < 2 || nextX > 100)
			{
				continue;
			}

			if (!parameter[nextY][nextX][k] || visited[nextY][nextX])
			{
				continue;
			}

			visited[nextY][nextX] = true;

			q.push({ nextY, nextX, cnt + 1 });
		}
	}

	return -1;
}