#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int solution(std::vector<int> a) {
	if (a.size() < 2)
	{
		return 0;
	}

	map<int, int> visited;

	for (int num : a)
	{
		visited[num]++;
	}

	vector<pair<int, int>> v(visited.begin(), visited.end());

	int answer = 0;

	for (auto data : v)
	{
		int num = data.first;
		int cnt = data.second;

		if (answer >= cnt)
		{
			continue;
		}

		int len = 0;

		for (int j = 0; j < a.size() - 1; j++)
		{
			if (a[j] != num && a[j + 1] != num)
			{
				continue;
			}

			if (a[j] == a[j + 1])
			{
				continue;
			}

			len++, j++;
		}

		answer = max(len, answer);
	}

	return answer * 2;
}

int main(void)
{
	vector<int> a = { 0, 0, 0, 2, 3, 4, 3, 5, 3, 1 };

	cout << solution(a) << "\n";

	return 0;
}