#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 987654321;
const int MAX = 100;

typedef struct
{
	int y, x;
} Dir;

Dir moveDir[4] = { { 0, 1 }, { 1, 0 }, { 0, -1 }, { -1, 0 }};

int arr[MAX][MAX];

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
	int idx = 1;
	
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			arr[i][j] = idx++;
		}
	}

	vector<int> answers;

	for (auto query : queries)
	{
		int leftY = query[0] - 1;
		int leftX = query[1] - 1;
		int rightY = query[2] - 1;
		int rightX = query[3] - 1;

		int minValue = INF;
		int next = arr[leftY][leftX];
		int before = arr[leftY][leftX];
		int y = leftY;
		int x = leftX;
		int dir = 0;

		while(1)
		{
			int nextY = y + moveDir[dir].y;
			int nextX = x + moveDir[dir].x;

			if (nextY < leftY || nextY > rightY || nextX < leftX || nextX > rightX)
			{
				dir++;

				continue;
			}

			next = arr[nextY][nextX];
			arr[nextY][nextX] = before;
			before = next;

			minValue = min(minValue, arr[nextY][nextX]);
			y = nextY;
			x = nextX;

			if (y == leftY && x == leftX)
			{
				break;
			}
		}

		answers.push_back(minValue);
	}

	return answers;
}

int main(void)
{
	int rows = 6;
	int columns = 6;
	vector<vector<int>> queries = {
		{2, 2, 5, 4},
		{3, 3, 6, 6},
		{5, 1, 6, 3}
	};

	vector<int> answers = solution(rows, columns, queries);

	for (int answer : answers)
	{
		cout << answer << " ";
	}

	cout << "\n";

	return 0;
}