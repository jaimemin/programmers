#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(int n) {
	int answer = 0;

	for (int i = 1; i <= n; i++)
	{
		int num = i;
		int sum = num;

		while (sum <= n)
		{
			if (sum == n)
			{
				answer++;
			}

			sum += ++num;
		}
	}

	return answer;
}