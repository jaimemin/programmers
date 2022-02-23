#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool isZero(vector<vector<int>> &board)
{
	for (vector<int> b : board)
	{
		for (int a : b)
		{
			if (a)
			{
				return false;
			}
		}
	}

	return true;
}

int solution(vector<vector<int>> board)
{
	if (isZero(board))
	{
		return 0;
	}

	int answer = 1;

	for (int i = 1; i < board.size(); i++)
	{
		for (int j = 1; j < board[i].size(); j++)
		{
			if (!board[i][j])
			{
				continue;
			}

			board[i][j] = min({ board[i - 1][j], board[i][j - 1], board[i - 1][j - 1] }) + 1;
			answer = max(answer, board[i][j] * board[i][j]);
		}
	}

	return answer;
}