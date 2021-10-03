#include <string>
#include <vector>
using namespace std;

const int MAX = 1000;

typedef struct
{
	int y, x;
} Dir;

Dir moveDir[3] = { { 1, 0 }, {0, 1}, {-1, -1} };

int triangle[MAX][MAX];

vector<int> solution(int n) {
	int y = -1, x = 0;
	int idx = 1;
	int dir = 0;

	while (1)
	{
		if (idx == n * (n + 1) / 2 + 1)
		{
			break;
		}

		int nextY = y + moveDir[dir].y;
		int nextX = x + moveDir[dir].x;
		
		if (nextY < 0 || nextY >= n || nextX < 0 || nextX >= n
			|| triangle[nextY][nextX])
		{
			dir = (dir + 1) % 3;

			continue;
		}

		triangle[nextY][nextX] = idx++;
		y = nextY;
		x = nextX;
	}

	vector<int> answers;

	for (int i = 0; i < n;i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (triangle[i][j])
			{
				answers.push_back(triangle[i][j]);
			}
		}
	}

	return answers;
}
