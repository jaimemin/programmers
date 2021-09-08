#include <iostream>
#include <string>
#include <vector>
using namespace std;

int result;

void func(int idx, vector<int> &numbers, int target, int sum)
{
	if (idx == numbers.size())
	{
		if (target == sum)
		{
			result++;
		}

		return;
	}

	func(idx + 1, numbers, target, sum + numbers[idx]);
	func(idx + 1, numbers, target, sum - numbers[idx]);
}

int solution(vector<int> numbers, int target) {
	func(0, numbers, target, 0);

	return result;
}

int main(void)
{
	vector<int> numbers = { 1, 1, 1, 1, 1 };
	int target = 3;

	cout << solution(numbers, target) << "\n";

	return 0;
}