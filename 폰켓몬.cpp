#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int solution(vector<int> nums)
{
	int answer = nums.size() / 2;

	map<int, bool> visited;
	int cnt = 0;

	for (int num : nums)
	{
		if (visited.count(num))
		{
			continue;
		}

		visited[num] = true;
		cnt++;
	}

	return min(answer, cnt);
}

int main(void)
{
	vector<int> nums = { 3, 1, 2, 3 };

	cout << solution(nums) << "\n";

	return 0;
}