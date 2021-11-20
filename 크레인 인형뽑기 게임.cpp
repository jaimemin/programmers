#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <deque>
using namespace std;

const int MAX = 30;

int solution(vector<vector<int>> board, vector<int> moves) {
	int answer = 0;
	queue<int> q[MAX];

	for (int i = 0; i < board.size(); i++)
	{
		for (int j = 0; j < board.size(); j++)
		{
			if (board[i][j])
			{
				q[j].push(board[i][j]);
			}
		}
	}

	deque<int> dq;

	for (int move : moves)
	{
		if (q[move - 1].empty())
		{
			continue;
		}

		int picked = q[move - 1].front();
		q[move - 1].pop();

		dq.push_front(picked);

		if (dq.size() >= 2 && dq[0] == dq[1])
		{
			for (int i = 0; i < 2; i++)
			{
				dq.pop_front();
				answer++;
			}
		}
	}

	return answer;
}