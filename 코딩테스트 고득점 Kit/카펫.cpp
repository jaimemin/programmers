#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(int brown, int yellow) {
	vector<int> answer;

	int total = brown + yellow;

	for (int row = 1; row < total; row++)
	{
		if (total % row)
		{
			continue;
		}

		int col = total / row;

		if ((row - 2) * (col - 2) == yellow)
		{
			answer = { max(row, col), min(row, col) };

			break;
		}
	}

	return answer;
}

int main(void)
{
	int brown = 24;
	int yellow = 24;

	vector<int> lens = solution(brown, yellow);

	for (int len : lens)
	{
		cout << len << " ";
	}

	cout << "\n";

	return 0;
}