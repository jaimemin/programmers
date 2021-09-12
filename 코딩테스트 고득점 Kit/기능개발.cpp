#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
	vector<int> answer;

	int priority = 0;

	while (1)
	{
		if (priority == progresses.size())
		{
			break;
		}

		for (int i = 0; i < progresses.size(); i++)
		{
			progresses[i] += speeds[i];
		}

		if (progresses[priority] < 100)
		{
			continue;
		}

		int cnt = 0;

		while (1)
		{
			if (priority == progresses.size() 
				|| progresses[priority] < 100)
			{
				break;
			}

			cnt++;
			priority++;
		}

		answer.push_back(cnt);
	}

	return answer;
}

int main(void)
{
	vector<int> progresses = { 95, 90, 99, 99, 80, 99 };
	vector<int> speeds = { 1, 1, 1, 1, 1, 1 };

	vector<int> cnts = solution(progresses, speeds);

	for (int cnt : cnts)
	{
		cout << cnt << " ";
	}

	cout << "\n";

	return 0;
}