#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
using namespace std;

const int MAX = 100;

typedef struct
{
	int y, x;
} Dir;

Dir moveDir[4] = { { 0, 1 },{ 0, -1 },{ 1, 0 },{ -1, 0 } };

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
	bool visited[MAX][MAX] = { false, };
	int number_of_area = 0;
	int max_size_of_one_area = 0;

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (picture[i][j] == 0
				|| visited[i][j])
			{
				continue;
			}

			number_of_area++;

			queue<pair<int, int>> q;
			q.push({ i, j });
			visited[i][j] = true;
			int color = picture[i][j];
			int cnt = 0;

			while (!q.empty())
			{
				int y = q.front().first;
				int x = q.front().second;
				q.pop();

				cnt++;

				for (int k = 0; k < 4; k++)
				{
					int nextY = y + moveDir[k].y;
					int nextX = x + moveDir[k].x;

					if (nextY < 0 || nextY >= m
						|| nextX < 0 || nextX >= n
						|| visited[nextY][nextX]
						|| picture[nextY][nextX] != color)
					{
						continue;
					}

					visited[nextY][nextX] = true;
					q.push({ nextY, nextX });
				}
			}

			max_size_of_one_area = max(max_size_of_one_area, cnt);
		}
	}

	vector<int> answer(2);
	answer[0] = number_of_area;
	answer[1] = max_size_of_one_area;

	return answer;
}