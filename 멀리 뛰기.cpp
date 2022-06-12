#include <string>
#include <vector>
#include <cmath>
using namespace std;

const long long MOD = 1234567;

const int MAX = 2000 + 200;

long long solution(int n) {
	long long fibo[MAX];

	fibo[0] = fibo[1] = 1;

	for (int i = 2; i <= n; i++)
	{
		fibo[i] = (fibo[i - 1] + fibo[i - 2]) % MOD;
	}

	return fibo[n];
}