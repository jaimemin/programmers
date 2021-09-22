#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAX = 500 + 50;

int result;
int cache[MAX][MAX];
vector<vector<int>> triangleCopy;

int func(int row, int col)
{
	if (row == triangleCopy.size())
	{
		return 0;
	}

	int &result = cache[row][col];

	if (result != -1)
	{
		return result;
	}

	result = triangleCopy[row][col] + max(func(row + 1, col), func(row + 1, col + 1));

	return result;
}

int solution(vector<vector<int>> triangle) {
	triangleCopy = triangle;
	memset(cache, -1, sizeof(cache));

	func(0, 0);

	return cache[0][0];
}

int main(void)
{
	vector<vector<int>> triangle = {
		{7},
		{3, 8},
		{8, 1, 0},
		{2, 7, 4, 4},
		{4, 5, 2, 6, 5}
	};

	cout << solution(triangle) << "\n";

	return 0;
}