#include <string>
#include <vector>
using namespace std;

int M, N;
vector<vector<int>> board;

bool canUnlock(int y, int x, vector<vector<int>> &key)
{
	bool flag = true;

	for (int curY = y; curY < y + M; curY++)
	{
		for (int curX = x; curX < x + M; curX++)
		{
			board[curY][curX] += key[curY - y][curX - x];
		}
	}

	for (int curY = M; curY < M + N; curY++)
	{
		for (int curX = M; curX < M + N; curX++)
		{
			if (board[curY][curX] != 1)
			{
				flag = false;

				break;
			}
		}

		if (flag == false)
		{
			break;
		}
	}

	for (int curY = y; curY < y + M; curY++)
	{
		for (int curX = x; curX < x + M; curX++)
		{
			board[curY][curX] -= key[curY - y][curX - x];
		}
	}

	return flag;
}

void rotate(vector<vector<int>> &key)
{
	vector<vector<int>> temp(M, vector<int>(M));

	for (int y = 0; y < M; y++)
	{
		for (int x = 0; x < M; x++)
		{
			temp[y][x] = key[x][M - (y + 1)];
		}
	}

	for (int y = 0; y < M; y++)
	{
		for (int x = 0; x < M; x++)
		{
			key[y][x] = temp[y][x];
		}
	}
}

void init(vector<vector<int>> &key, vector<vector<int>> &lock)
{
	M = key.size();
	N = lock.size();
	board = vector<vector<int>>(2 * M + N, vector<int>(2 * M + N));
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
	init(key, lock);

	for (int y = M; y < M + N; y++)
	{
		for (int x = M; x < M + N; x++)
		{
			board[y][x] = lock[y - M][x - M];
		}
	}

	for (int y = 0; y < M + N; y++)
	{
		for (int x = 0; x < M + N; x++)
		{
			for (int k = 0; k < 4; k++)
			{
				if (canUnlock(y, x, key))
				{
					return true;
				}

				rotate(key);
			}
		}
	}

	return false;
}