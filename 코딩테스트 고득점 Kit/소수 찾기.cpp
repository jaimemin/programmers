#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

const int MAX = 10000000;

set<int> candidates;
int minFactor[MAX];

void eratosthenes(void)
{
	minFactor[0] = minFactor[1] = -1;

	for (int i = 2; i < MAX; i++)
	{
		minFactor[i] = i;
	}

	for (int i = 2; i < MAX; i++)
	{
		if (minFactor[i] != i)
		{
			continue;
		}

		for (int j = i * i; j < MAX; j += i)
		{
			if (minFactor[j] == j)
			{
				minFactor[j] = i;
			}
		}
	}
}

void func(string curNum, int count[10], int len, string numbers)
{
	if (len == curNum.length())
	{
		candidates.insert(stoi(curNum));

		return;
	}

	for (char number : numbers)
	{
		if (count[number - '0'])
		{
			count[number - '0']--;
			func(curNum + number, count, len, numbers);
			count[number - '0']++;
		}
	}
}

int solution(string numbers) {
	eratosthenes();

	int count[10] = { 0, };

	for (int i = 0; i < numbers.size(); i++)
	{
		count[numbers[i] - '0']++;
	}

	for (int i = 1; i <= numbers.length(); i++)
	{
		func("", count, i, numbers);
	}

	int result = 0;

	for (int candidate : candidates)
	{
		if (minFactor[candidate] == candidate)
		{
			result++;
		}
	}

	return result;
}

int main(void)
{
	string numbers = "17";

	cout << solution(numbers) << "\n";

	return 0;
}