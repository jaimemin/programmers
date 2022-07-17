#include <vector>
#include <algorithm>
#include <climits>
#include <iostream>
using namespace std;

const int MAX = 1320 + 1;

int getDistance(pair<int, int> a, pair<int, int> b)
{
	return abs(a.first - b.first) + abs(a.second - b.second);
}

bool canPlaceFurther(pair<int, int> coord, int maxDistance, vector<pair<int, int>> &people)
{
	for (pair<int, int> p : people)
	{
		if (getDistance(p, coord) < maxDistance)
		{
			return false;
		}
	}

	return true;
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int n, int m, vector<vector<int>> timetable) {
	int numberOfPeople[MAX] = { 0, };
	int start = INT_MAX;
	int end = 0;

	for (vector<int> t : timetable)
	{
		for (int i = t[0]; i <= t[1]; i++)
		{
			numberOfPeople[i]++;
			start = min(start, i);
			end = max(end, i);
		}
	}

	int maxCrowded = 0;

	for (int i = start; i <= end; i++)
	{
		maxCrowded = max(maxCrowded, numberOfPeople[i]);
	}

	if (maxCrowded <= 1)
	{
		return 0;
	}

	for (int distance = 2 * n - 2; distance > 0; distance--)
	{
		for (int y = 0; y < n; y++)
		{
			for (int x = 0; x < n; x++)
			{
				vector<pair<int, int>> people;
				people.push_back({ y, x });

				for (int y2 = y; y2 < n; y2++)
				{
					for (int x2 = 0; x2 < n; x2++)
					{
						if (y2 == y && x2 <= x)
						{
							continue;
						}

						if (canPlaceFurther({ y2, x2 }, distance, people))
						{
							people.push_back({ y2, x2 });
						}

						if (people.size() == maxCrowded)
						{
							return distance;
						}
					}
				}
			}
		}
	}

	return 0;
}
