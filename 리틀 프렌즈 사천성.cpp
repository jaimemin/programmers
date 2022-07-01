#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <iostream>
using namespace std;

const int MAX = 100;

typedef struct
{
	int y, x;
} Dir;

typedef struct
{
	int y, x;
	int cnt;
	int prevDir;
} State;

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
string solution(int m, int n, vector<string> board) {
	vector<pair<int, int>> v[26];
	Dir moveDir[4] = { { 1, 0 },{ 0, 1 },{ 0, -1 },{ -1, 0 } };
	set<char> characters;

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (board[i][j] >= 'A' && board[i][j] <= 'Z')
			{
				characters.insert(board[i][j]);

				v[board[i][j] - 'A'].push_back({ i, j });
			}
		}
	}

	string answer = "";

	while (characters.size() > 0)
	{
		bool canErase = false;

		for (char c : characters)
		{
			pair<int, int> start = v[c - 'A'][0];
			pair<int, int> end = v[c - 'A'][1];

			queue<State> q;
			q.push({ start.first, start.second, -1, -1 });

			bool visited[MAX][MAX][3][4] = { false, };

			while (!q.empty())
			{
				State cur = q.front();
				int y = cur.y;
				int x = cur.x;
				int cnt = cur.cnt;
				int prevDir = cur.prevDir;
				q.pop();

				if (cnt >= 2)
				{
					continue;
				}

				if (characters.size() == 1 && c == 'E') {
					cout << y << " " << x << " " << cnt << " " << prevDir << '\n';
				}

				if (y == end.first && x == end.second)
				{
					answer += c;
					characters.erase(c);
					canErase = true;
					board[start.first][start.second] = '.';
					board[end.first][end.second] = '.';

					break;
				}

				for (int k = 0; k < 4; k++)
				{
					int nextY = y + moveDir[k].y;
					int nextX = x + moveDir[k].x;

					if (nextY < 0 || nextY >= m || nextX < 0 || nextX >= n)
					{
						continue;
					}

					if (prevDir != -1 && visited[nextY][nextX][cnt][prevDir]) {
						continue;
					}

					if (!(board[nextY][nextX] == c || board[nextY][nextX] == '.'))
					{
						continue;
					}

					if (characters.size() == 1 && c == 'E') {
						cout << "NEXT: " << nextY << " " << nextX << " " << k << " " << prevDir << "\n";
					}

					visited[nextY][nextX][prevDir != k ? cnt + 1 : cnt][k] = true;
					q.push({ nextY, nextX, prevDir != k ? cnt + 1 : cnt, k });
				}
			}

			if (canErase)
			{
				break;
			}
		}

		if (canErase == false)
		{
			return "IMPOSSIBLE";
		}
	}

	return answer;
}