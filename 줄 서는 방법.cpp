#include <string>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 20 + 2;

long long getFactorial(int n) {
	long long result = 1;

	for (int i = 1; i <= n; i++) {
		result *= i;
	}

	return result;
}

vector<int> solution(int n, long long k) {
	vector<int> answer;
	vector<int> v;
	int cnt = 1;

	for (int i = 1; i <= n; i++)
	{
		v.push_back(i);
	}

	while (cnt != n)
	{
		long long factorial = getFactorial(n - cnt++);
		int idx = (k - 1) / factorial;

		answer.push_back(v[idx]);
		v.erase(v.begin() + idx);
		k %= factorial;

		if (k == 0)
		{
			k = factorial;
		}
	}

	answer.push_back(v[0]);

	return answer;
}