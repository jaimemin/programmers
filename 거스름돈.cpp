#include <string>
#include <vector>
#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;

const int MOD = 1e9 + 7;

const int MAX = 1e5 + 1;

int cache[MAX];

int solution(int n, vector<int> money) {
	for (int i = 0; i <= n; i++)
	{
		cache[i] = !(i % money[0]);
	}

	for (int i = 1; i < money.size(); i++)
	{
		for (int j = money[i]; j <= n; j++)
		{
			cache[j] = (cache[j] + cache[j - money[i]]) % MOD;
		}
	}

	return cache[n];
}

int main(void)
{
	cout << solution(5, { 1, 2, 5 }) << "\n";

	return 0;
}