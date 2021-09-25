#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(int distance, vector<int> rocks, int n) {
	sort(rocks.begin(), rocks.end());

	int left = 1, right = distance;
	int result = 0;

	while (left + 1 < right)
	{
		int mid = (left + right) / 2;

		int removedCnt = 0;
		int lastRock = 0;

		for (int rock : rocks)
		{
			if (mid > (rock - lastRock))
			{
				removedCnt++;
			}
			else
			{
				lastRock = rock;
			}
		}

		if (removedCnt <= n)
		{
			left = mid;
		}
		else
		{
			right = mid;
		}
	}

	return left;
}

int main(void)
{
	int distance = 25;
	vector<int> rocks = { 2, 14, 11, 21, 17 };
	int n = 2;

	cout << solution(distance, rocks, n) << "\n";

	return 0;
}