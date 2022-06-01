#include <string>
#include <vector>
#include <cstring>
using namespace std;

const int MAX = 60000 + 600;

const int MOD = 1000000007;

long long cache[MAX];

long long tiling(int width)
{
	if (width <= 1)
	{
		return 1;
	}

	long long &result = cache[width];

	if (result != -1)
	{
		return result;
	}

	result = (tiling(width - 2) + tiling(width - 1)) % MOD;

	return result;
}

int solution(int n) {
	memset(cache, -1, sizeof(cache));

	return tiling(n);
}