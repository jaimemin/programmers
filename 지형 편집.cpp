#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

const int MAX = 1e9 + 1e7;

long long getTotalCost(long long mid, vector<vector<int>> &land, int P, int Q)
{
	long long cost = 0;

	for (int i = 0; i < land.size(); i++)
	{
		for (int j = 0; j < land.size(); j++)
		{
			long long diff = land[i][j] * 1LL - mid;

			cost += diff >= 0 ? diff * Q : diff * -P;
		}
	}

	return cost;
}

long long solution(vector<vector<int> > land, int P, int Q) {
	long long left = LLONG_MAX;
	long long right = 0;

	for (int i = 0; i < land.size(); i++)
	{
		for (int j = 0; j < land.size(); j++)
		{
			left = min(left, land[i][j] * 1LL);
			right = max(right, land[i][j] * 1LL);
		}
	}

	long long answer = LLONG_MAX;

	while (left <= right)
	{
		long long mid = (left + right) / 2;

		long long candidate = getTotalCost(mid, land, P, Q);
		long long candidate2 = getTotalCost(mid + 1, land, P, Q);

		if (candidate == candidate2)
		{
			answer = min(answer, candidate);

			break;
		}
		
		if (candidate > candidate2)
		{
			answer = min(answer, candidate2);

			left = mid + 1;
		}
		else if (candidate < candidate2)
		{
			answer = min(answer, candidate);

			right = mid - 1;
		}
	}

	return answer;
}

int main(void)
{
	vector<vector<int>> land = {
		{ 4, 4, 3 },
		{ 3, 2, 2 },
		{ 2, 1, 0 }
	};
	int P = 5;
	int Q = 3;

	cout << solution(land, P, Q) << "\n";

	return 0;
}