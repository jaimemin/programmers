#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstring>
using namespace std;

const int INF = 987654321;
const int MAX = 200 + 20;

int cache[MAX][MAX][2];
vector<int> numbers;
vector<string> ops;

void init(vector<string> arr)
{
	for (int i = 0; i < arr.size(); i++)
	{
		if (i % 2 == 0)
		{
			numbers.push_back(stoi(arr[i]));
		}
		else
		{
			ops.push_back(arr[i]);
		}
	}
}

int func(int start, int end, bool isMax)
{
	int &result = cache[start][end][isMax];

	if (result != -1)
	{
		return result;
	}

	if (start == end)
	{
		return result = numbers[start];
	}

	result = isMax ? -INF : INF;

	for (int i = start; i < end; i++)
	{
		if (ops[i] == "-")
		{
			result = isMax ?
				max(result, func(start, i, true) - func(i + 1, end, false)) :
				min(result, func(start, i, false) - func(i + 1, end, true));
		}
		else
		{
			result = isMax ?
				max(result, func(start, i, true) + func(i + 1, end, true)) :
				min(result, func(start, i, false) + func(i + 1, end, false));
		}
	}

	return result;
}

int solution(vector<string> arr)
{
	init(arr);

	memset(cache, -1, sizeof(cache));

	return func(0, arr.size() / 2, true);
}

int main(void)
{
	vector<string> arr = { "1", "-", "3", "+", "5", "-", "8" };

	cout << solution(arr) << "\n";

	return 0;
}