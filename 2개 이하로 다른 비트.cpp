#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

long long getMinNum(long long N)
{
	if (N % 2 == 0)
	{
		return N + 1;
	}

	long long bit = 1;

	while (N & bit)
	{
		bit *= 2;
	}

	return N + bit / 2;
}

vector<long long> solution(vector<long long> numbers) {
	vector<long long> answer;

	for (long long number : numbers)
	{
		answer.push_back(getMinNum(number));
	}

	return answer;
}