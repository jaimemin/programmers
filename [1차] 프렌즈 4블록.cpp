#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

typedef struct
{
	int y, x;
	char character;
} Block;

int eraseBlocks(vector<string> &board)
{
	queue<pair<int, int>> q;

	for (int y = 0; y < board.size() - 1; y++)
	{
		for (int x = 0; x < board[y].length() - 1; x++)
		{
			char block = board[y][x];

			if (block == ' ')
			{
				continue;
			}

			if (board[y + 1][x] == block
				&& board[y][x + 1] == block
				&& board[y + 1][x + 1] == block)
			{
				q.push({ y, x });
			}
		}
	}

	int cnt = 0;

	while (!q.empty())
	{
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		if (board[y][x] != 'X')
		{
			cnt++;

			board[y][x] = 'X';
		}

		if (board[y + 1][x] != 'X')
		{
			cnt++;

			board[y + 1][x] = 'X';
		}

		if (board[y][x + 1] != 'X')
		{
			cnt++;

			board[y][x + 1] = 'X';
		}

		if (board[y + 1][x + 1] != 'X')
		{
			cnt++;

			board[y + 1][x + 1] = 'X';
		}
	}

	for (int y = board.size() - 1; y >= 1; y--)
	{
		for (int x = 0; x < board[y].length(); x++)
		{
			if (board[y][x] != 'X')
			{
				continue;
			}

			while (board[y][x] == 'X')
			{
				queue<Block> blockQ;

				for (int curY = y - 1; curY >= 0; curY--)
				{
					blockQ.push({ curY, x, board[curY][x] });
				}

				while (!blockQ.empty())
				{
					int curY = blockQ.front().y;
					int curX = blockQ.front().x;
					char curCharacter = blockQ.front().character;
					blockQ.pop();

					board[curY + 1][curX] = curCharacter;
					board[curY][curX] = ' ';
				}
			}
		}
	}

	return cnt;
}

int solution(int m, int n, vector<string> board) {
	int answer = 0;

	while (1)
	{
		int cnt = eraseBlocks(board);

		if (cnt == 0)
		{
			break;
		}

		answer += cnt;
	}

	return answer;
}

int main(void)
{
	int m = 4;
	int n = 5;
	vector<string> board = { "CCBDE", "AAADE", "AAABF", "CCBBF" };

	cout << solution(m, n, board) << "\n";

	return 0;
}