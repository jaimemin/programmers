#include <vector>
#include <iostream>
using namespace std;

const int MAX = 50000 + 500;

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

int solution(vector<int> nums) {
	eratosthenes();

	int answer = 0;

	for (int i = 0; i < nums.size(); i++)
	{
		for (int j = i + 1; j < nums.size(); j++)
		{
			for (int k = j + 1; k < nums.size(); k++)
			{
				int sum = nums[i] + nums[j] + nums[k];

				if (minFactor[sum] == sum)
				{
					answer++;
				}
			}
		}
	}

	return answer;
}

int main(void)
{
	vector<int> nums = { 1, 2, 3, 4 };

	cout << solution(nums) << "\n";

	return 0;
}