#include <string>
#include <vector>
#include <cstring>
#include <iostream>
using namespace std;

const int MAX = 5000 + 50;

const int MOD = 1000000007;

long long cache[MAX];

long long tiling(int width)
{
	if (width % 2)
	{
		return 0;
	}

	if (width == 0)
	{
		return 1;
	}

	if (width == 2)
	{
		return 3;
	}

	long long &result = cache[width];

	if (result != -1)
	{
		return result;
	}

	result = 3 * tiling(width - 2);

	for (int i = 0; i <= width - 4; i += 2)
	{
		result += 2 * tiling(i);
	}

	result %= MOD;

	return result;
}

int solution(int n) {
	memset(cache, -1, sizeof(cache));

	return tiling(n);
}

int main(void)
{
	for (int width = 2; width <= 5000; width += 2)
	{
		cout << width << ": " << solution(width) << "\n";
	}

	return 0;
}