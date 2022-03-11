#include <string>
#include <vector>
using namespace std;

const int MAX = 1e5;

const int MOD = 1234567;

long long cache[MAX];

int solution(int n) {
	cache[0] = cache[1] = 1;

	for (int i = 2; i < n; i++)
	{
		cache[i] = cache[i - 1] + cache[i - 2];
		cache[i] %= MOD;
	}

	return cache[n - 1];
}