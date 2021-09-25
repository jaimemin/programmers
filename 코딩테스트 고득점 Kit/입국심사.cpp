#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

long long solution(int n, vector<int> times) {
	sort(times.begin(), times.end());

	long long left = 0, right = times.back() * (n * 1LL);

	while (left + 1 < right)
	{
		long long mid = (left + right) / 2;
		long long sum = 0;

		for (int time : times)
		{
			sum += mid / (time * 1LL);
		}

		if (sum >= (n * 1LL))
		{
			right = mid;
		}
		else
		{
			left = mid;
		}
	}

	return right;
}

int main(void)
{
	int n = 6;
	vector<int> times = { 7, 10 };

	cout << solution(n, times) << "\n";

	return 0;
}