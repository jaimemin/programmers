#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <cstring>
using namespace std;

const int BOARD_MAX = 50;

typedef struct
{
	int y, x;
} Coord;

bool operator<(const Coord &a, const Coord &b)
{
	if (a.y < b.y)
	{
		return true;
	}

	if (a.y == b.y && a.x < b.x)
	{
		return true;
	}

	return false;
}

class Block
{
public:
	vector<Coord> coords;

	void addCoords(Coord coord)
	{
		coords.push_back(coord);
	}

	void rotate90(void)
	{
		int minTop = BOARD_MAX;
		int minLeft = BOARD_MAX;

		vector<Coord> tempCoords;

		// 90µµ È¸Àü
		// https://calcworkshop.com/transformations/rotation-rules/
		for (Coord coord : coords)
		{
			tempCoords.push_back({ coord.x * - 1, coord.y });

			minTop = min(minTop, coord.x * -1);
			minLeft = min(minLeft, coord.y);
		}

		coords.clear();

		for (Coord coord : tempCoords)
		{
			coords.push_back({ coord.y - minTop, coord.x - minLeft });
		}
	}
};

typedef struct
{
	int y, x;
} Dir;

Dir moveDir[4] = { {-1, 0}, {1, 0}, {0, 1}, {0, -1} };

int result = 0;
int boardLength = 0;
int gameBoard[BOARD_MAX][BOARD_MAX];
int argumentTable[BOARD_MAX][BOARD_MAX];

bool visited[BOARD_MAX][BOARD_MAX];
vector<Block> candidateBlocks;
vector<Block> emptyBlocks;
vector<bool> candidateBlocksVisited;

void init(vector<vector<int>> game_board, vector<vector<int>> table)
{
	boardLength = game_board.size();

	for (int i = 0; i < game_board.size(); i++)
	{
		for (int j = 0; j < game_board[i].size(); j++)
		{
			gameBoard[i][j] = game_board[i][j];
		}
	}

	for (int i = 0; i < table.size(); i++)
	{
		for (int j = 0; j < table[i].size(); j++)
		{
			argumentTable[i][j] = table[i][j];
		}
	}
}

vector<Coord> getArrangedCoords(vector<Coord> tempCoords)
{
	int minTop = BOARD_MAX;
	int minLeft = BOARD_MAX;

	for (Coord coord : tempCoords)
	{
		minTop = min(minTop, coord.y);
		minLeft = min(minLeft, coord.x);
	}

	vector<Coord> coords;

	for (Coord coord : tempCoords)
	{
		coords.push_back({ coord.y - minTop, coord.x - minLeft });
	}

	return coords;
}

Block getCandidateBlock(int y, int x)
{
	queue<Coord> q;
	q.push({ y, x });
	visited[y][x] = true;

	Block block;
	vector<Coord> tempCoords;

	while (!q.empty())
	{
		Coord cur = q.front();
		q.pop();

		for (int k = 0; k < 4; k++)
		{
			int nextY = cur.y + moveDir[k].y;
			int nextX = cur.x + moveDir[k].x;

			if (nextY < 0 || nextY >= boardLength || nextX < 0 || nextX >= boardLength)
			{
				continue;
			}

			if (visited[nextY][nextX] || argumentTable[nextY][nextX] == 0)
			{
				continue;
			}

			visited[nextY][nextX] = true;
			q.push({ nextY, nextX });
		}

		tempCoords.push_back({ cur.y, cur.x });
	}

	vector<Coord> arrangedCoords = getArrangedCoords(tempCoords);

	for (Coord coord : arrangedCoords)
	{
		block.addCoords(coord);
	}

	return block;
}

Block getEmptyBlock(int y, int x)
{
	queue<Coord> q;
	q.push({ y, x });
	visited[y][x] = true;

	Block block;
	vector<Coord> tempCoords;

	while (!q.empty())
	{
		Coord cur = q.front();
		q.pop();

		for (int k = 0; k < 4; k++)
		{
			int nextY = cur.y + moveDir[k].y;
			int nextX = cur.x + moveDir[k].x;

			if (nextY < 0 || nextY >= boardLength || nextX < 0 || nextX >= boardLength)
			{
				continue;
			}

			if (visited[nextY][nextX] || gameBoard[nextY][nextX])
			{
				continue;
			}

			visited[nextY][nextX] = true;
			q.push({ nextY, nextX });
		}

		tempCoords.push_back({ cur.y, cur.x });
	}

	vector<Coord> arrangedCoords = getArrangedCoords(tempCoords);

	for (Coord coord : arrangedCoords)
	{
		block.addCoords(coord);
	}

	return block;
}

void getCandidates(void)
{
	for (int y = 0; y < boardLength; y++)
	{
		for (int x = 0; x < boardLength; x++)
		{
			if (visited[y][x] || argumentTable[y][x] == 0)
			{
				continue;
			}

			candidateBlocks.push_back(getCandidateBlock(y, x));
		}
	}
}

void getEmptyBlocks(void)
{
	memset(visited, false, sizeof(visited));

	for (int y = 0; y < boardLength; y++)
	{
		for (int x = 0; x < boardLength; x++)
		{
			if (visited[y][x] || gameBoard[y][x])
			{
				continue;
			}

			emptyBlocks.push_back(getEmptyBlock(y, x));
		}
	}
}

bool isCandidateEqualToEmpty(Block emptyBlock, Block candidate)
{
	if (emptyBlock.coords.size() != candidate.coords.size())
	{
		return false;
	}

	map<Coord, bool> visited;

	for (Coord coord : emptyBlock.coords)
	{
		visited[coord] = true;
	}

	for (Coord coord : candidate.coords)
	{
		if (visited[coord] == false)
		{
			return false;
		}
	}

	return true;
}

void func(int idx, int cnt)
{
	if (idx == emptyBlocks.size())
	{
		result = max(result, cnt);

		return;
	}

	for (int i = 0; i < candidateBlocks.size(); i++)
	{
		if (candidateBlocksVisited[i])
		{
			continue;
		}

		for (int k = 0; k < 4; k++)
		{
			if (isCandidateEqualToEmpty(emptyBlocks[idx], candidateBlocks[i]))
			{

				candidateBlocksVisited[i] = true;
				func(idx + 1, cnt + candidateBlocks[i].coords.size());

				break;
			}

			candidateBlocks[i].rotate90();
		}
	}

	func(idx + 1, cnt);
}

int solution(vector<vector<int>> game_board, vector<vector<int>> table) {
	// ÀüÃ³¸®
	init(game_board, table);
	getCandidates();
	getEmptyBlocks();

	candidateBlocksVisited.resize(candidateBlocks.size(), false);
	func(0, 0);

	return result;
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	vector<vector<int>> game_board{
		{1, 1, 0, 0, 1, 0 },
		{0, 0, 1, 0, 1, 0 },
		{0, 1, 1, 0, 0, 1 },
		{1, 1, 0, 1, 1, 1 },
		{1, 0, 0, 0, 1, 0 },
		{0, 1, 1, 1, 0, 0 }
	};

	vector<vector<int>> table {
		{ 1, 0, 0, 1, 1, 0 },
		{ 1, 0, 1, 0, 1, 0 },
		{ 0, 1, 1, 0, 1, 1 },
		{ 0, 0, 1, 0, 0, 0 },
		{ 1, 1, 0, 1, 1, 0 },
		{ 0, 1, 0, 0, 0, 0 }
	};

	cout << solution(game_board, table) << "\n";

	return 0;
}
