#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 50000;

int solution(vector<int> people, int limit) {
	sort(people.begin(), people.end());

	int answer = 0;
	bool visited[MAX] = { 0, };

	for (int idx = 0, rIdx = people.size() - 1; idx < rIdx;)
	{
		int sum = people[idx] + people[rIdx];

		if (sum <= limit)
		{
			answer++;
			visited[idx++] = true;
			visited[rIdx--] = true;
		}
		else
		{
			rIdx--;
		}
	}

	for (int i = 0; i < people.size(); i++)
	{
		answer += !visited[i];
	}

	return answer;
}

int main(void)
{
	vector<int> people = { 70, 50, 80, 50 };
	int limit = 100;

	cout << solution(people, limit) << "\n";

	return 0;
}