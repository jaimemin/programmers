#include <string>
#include <vector>
#include <iostream>
using namespace std;

const int MAX = 1000 + 10;

int pSum[MAX][MAX];

int solution(vector<vector<int>> board, vector<vector<int>> skill) {
	for (vector<int> v : skill)
	{
		int type = v[0];
		int r1 = v[1];
		int c1 = v[2];
		int r2 = v[3];
		int c2 = v[4];
		int degree = v[5] * (type == 1 ? -1 : 1);

		pSum[r1][c1] += degree;
		pSum[r2 + 1][c2 + 1] += degree;

		pSum[r1][c2 + 1] -= degree;
		pSum[r2 + 1][c1] -= degree;
	}

	for (int y = 0; y < board.size(); y++)
	{
		for (int x = 1; x < board[0].size(); x++)
		{
			pSum[y][x] += pSum[y][x - 1];
		}
	}

	for (int x = 0; x < board[0].size(); x++)
	{
		for (int y = 1; y < board.size(); y++)
		{
			pSum[y][x] += pSum[y - 1][x];
		}
	}

	int answer = 0;

	for (int y = 0; y < board.size(); y++)
	{
		for (int x = 0; x < board[0].size(); x++)
		{
			answer += board[y][x] + pSum[y][x] > 0 ? 1 : 0;
		}
	}

	return answer;
}