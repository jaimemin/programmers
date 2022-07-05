#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <climits>
using namespace std;

long long solution(int a, int b, vector<int> g, vector<int> s, vector<int> w, vector<int> t) {
	long long answer = LLONG_MAX;
	long long left = 0, right = 1e5 + (1e5 * 2) * (2 * 1e9);

	while (left <= right)
	{
		long long mid = (left + right) / 2;
		long long gold = 0;
		long long silver = 0;
		long long weight = 0;

		for (int i = 0; i < t.size(); i++)
		{
			long long cnt = (mid + t[i]) / (2 * t[i]);
			gold += min(g[i] * 1LL, w[i] * cnt * 1LL);
			silver += min(s[i] * 1LL, w[i] * cnt * 1LL);
			weight += min((g[i] + s[i]) * 1LL, w[i] * cnt * 1LL);
		}

		if (weight >= a + b
			&& gold >= a
			&& silver >= b)
		{
			answer = min(answer, mid);
			right = mid - 1;
		}
		else
		{
			left = mid + 1;
		}
	}

	return answer;
}