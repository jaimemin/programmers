#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int N, M;

typedef struct
{
	int turn;
	bool winnable;
} State;

typedef struct
{
	int y, x;
} Dir;

Dir moveDir[4] = { { 1, 0 },{ -1, 0 },{ 0, 1 },{ 0, -1 } };

bool isInRange(int y, int x)
{
	return y >= 0 && y < N && x >= 0 && x < M;
}

bool tileExists(int y, int x, int boardBit)
{
	return boardBit & (1 << (N * M - (y * M + x + 1)));
}

int switchTile(int y, int x, int boardBit)
{
	return boardBit ^ (1 << (N * M - (y * M + x + 1)));
}

bool canNotMove(int y, int x, int boardBit)
{
	for (int k = 0; k < 4; k++)
	{
		int nextY = y + moveDir[k].y;
		int nextX = x + moveDir[k].x;

		if (isInRange(nextY, nextX) && tileExists(nextY, nextX, boardBit))
		{
			return false;
		}
	}

	return true;
}

State func(int y, int x, int y2, int x2, int boardBit)
{
	if (canNotMove(y, x, boardBit))
	{
		return { 0, false };
	}

	if (y == y2 && x == x2)
	{
		return { 1, true };
	}

	bool winnable = false;
	int minTurn = INT_MAX;
	int maxTurn = 0;

	for (int k = 0; k < 4; k++)
	{
		int nextY = y + moveDir[k].y;
		int nextX = x + moveDir[k].x;

		if ((isInRange(nextY, nextX) && tileExists(nextY, nextX, boardBit)) == false)
		{
			continue;
		}

		boardBit = switchTile(y, x, boardBit);
		State state = func(y2, x2, nextY, nextX, boardBit);
		boardBit = switchTile(y, x, boardBit);

		if (state.winnable == false)
		{
			winnable = true;

			minTurn = min(minTurn, state.turn);
		}
		else if (winnable == false)
		{
			maxTurn = max(maxTurn, state.turn);
		}
	}

	int turn = winnable ? minTurn : maxTurn;

	return { turn + 1, winnable };
}

int solution(vector<vector<int>> board, vector<int> aloc, vector<int> bloc) {
	N = board.size();
	M = board[0].size();
	int boardBit = 0;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (board[i][j])
			{
				boardBit |= 1 << (N * M - (i * M + j + 1));
			}
		}
	}

	cout << boardBit << "\n";

	State result = func(aloc[0], aloc[1], bloc[0], bloc[1], boardBit);

	return result.turn;
}