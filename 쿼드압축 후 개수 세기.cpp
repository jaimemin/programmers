#include <iostream>
#include <string>
#include <vector>
using namespace std;

const int MAX = 1024;

vector<int> answers;
bool visited[MAX][MAX];

void func(vector<vector<int>> &arr, int N, int leftY, int leftX, int rightY, int rightX)
{
	if (N == 1)
	{
		return;
	}

	bool canBeGrouped = true;
	int value = arr[leftY][leftX];

	for (int y = leftY; y < rightY; y++)
	{
		for (int x = leftX; x < rightX; x++)
		{
			if (arr[y][x] != value)
			{
				canBeGrouped = false;

				break;
			}
		}

		if (canBeGrouped == false)
		{
			break;
		}
	}

	if (!canBeGrouped)
	{
		func(arr, N / 2, leftY, leftX, leftY + N / 2, leftX + N / 2);
		func(arr, N / 2, leftY, leftX + N / 2, leftY + N / 2, rightX);
		func(arr, N / 2, leftY + N / 2, leftX, rightY, leftX + N / 2);
		func(arr, N / 2, leftY + N / 2, leftX + N / 2, rightY, rightX);

		return;
	}

	answers[value]++;

	for (int y = leftY; y < rightY; y++)
	{
		for (int x = leftX; x < rightX; x++)
		{
			visited[y][x] = true;
		}
	}
}

vector<int> solution(vector<vector<int>> arr) {
	answers.resize(2, 0);

	func(arr, arr.size(), 0, 0, arr.size(), arr.size());

	for (int i = 0; i < arr.size(); i++)
	{
		for (int j = 0; j < arr.size(); j++)
		{
			if (visited[i][j])
			{
				continue;
			}

			answers[arr[i][j]]++;
		}
	}

	return answers;
}

int main(void)
{
	vector<vector<int>> arr = {
		{ 1,1,0,0 },
		{ 1,0,0,0 },
		{ 1,0,0,1 },
		{ 1,1,1,1 }
	};

	vector<int> answers = solution(arr);

	for (int answer : answers)
	{
		cout << answer << " ";
	}

	cout << "\n";

	return 0;
}