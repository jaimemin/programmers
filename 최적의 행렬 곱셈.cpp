#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <set>
#include <cstring>
#include <climits>
using namespace std;

const int MAX = 200 + 20;

int cache[MAX][MAX];

int func(int start, int end, vector<vector<int>> &matrix_sizes)
{
	if (start == end)
	{
		return 0;
	}

	int &result = cache[start][end];

	if (result != -1)
	{
		return result;
	}

	result = INT_MAX;

	for (int i = start; i < end; i++)
	{
		int calcCost = matrix_sizes[start][0] * matrix_sizes[i][1] * matrix_sizes[end][1];

		result = min(result, func(start, i, matrix_sizes) + func(i + 1, end, matrix_sizes) + calcCost);
	}
	
	return result;
}

int solution(vector<vector<int>> matrix_sizes) {
	memset(cache, -1, sizeof(cache));

	return func(0, matrix_sizes.size() - 1, matrix_sizes);
}

int main(void)
{
	vector<vector<int>> matrix_sizes = {
		{ 5, 3 },
		{ 3, 10 },
		{ 10, 6 } 
	};

	cout << solution(matrix_sizes) << "\n";

	return 0;
}