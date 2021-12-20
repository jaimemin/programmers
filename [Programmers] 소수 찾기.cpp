#include <string>
#include <vector>
using namespace std;

const int MAX = 1000000 + 1000;

int minFactor[MAX];

void eratosthenes(void)
{
	minFactor[0] = minFactor[1] = -1;

	for (int i = 2; i < MAX; i++)
	{
		minFactor[i] = i;
	}

	for (int i = 2; i * i < MAX; i++)
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

int solution(int n) {
	eratosthenes();

	int answer = 0;

	for (int i = 2; i <= n; i++)
	{
		answer += (minFactor[i] == i);
	}

	return answer;
}