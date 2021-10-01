#include <iostream>
#include <algorithm>
using namespace std;

long long getGCD(int w, int h)
{
	if (w % h == 0)
	{
		return h;
	}

	return getGCD(h, w % h);
}

long long solution(int w, int h) {
	long long a = max(w, h) * 1LL;
	long long b = min(w, h) * 1LL;

	return a * b - (a + b - getGCD(a, b));
}