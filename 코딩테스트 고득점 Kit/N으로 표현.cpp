#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

const int MAX = 8;

int solution(int N, int number) {
	vector<set<int>> numbers(MAX + 1);
	int temp = 0;

	for (int i = 1; i <= MAX; i++)
	{
		temp = temp * 10 + N;
		numbers[i].insert(temp);

		for (int j = 1; j < i; j++)
		{
			for (auto a : numbers[j])
			{
				for (auto b : numbers[i - j])
				{
					// [N을 j번], [N을 (i - j)번] 사칙연산 진행하면
					// [N을 i번] 썼다는 뜻
					numbers[i].insert(a + b);
					numbers[i].insert(a - b);
					numbers[i].insert(a * b);

					if (b)
					{
						numbers[i].insert(a / b);
					}
				}
			}
		}

		if (numbers[i].find(number) != numbers[i].end())
		{
			return i;
		}
	}

	return -1;
}

int main(void)
{
	int N = 5;
	int number = 12;

	cout << solution(N, number) << "\n";

	return 0;
}