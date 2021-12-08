#include <string>
#include <vector>
#include <algorithm>
using namespace std;

long long solution(int a, int b) {
	if (a == b)
	{
		return a;
	}

	long long answer = 0;

	for (int i = min(a, b); i <= max(a, b); i++)
	{
		answer += i;
	}

	return answer;
}