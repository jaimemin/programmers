#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> students[3];

void init(void)
{
	students[0] = { 1, 2, 3, 4, 5 };
	students[1] = { 2, 1, 2, 3, 2, 4, 2, 5, 2 };
	students[2] = { 3, 3, 1, 1, 2, 2, 4, 4, 5, 5 };
}

vector<int> getSmartestStudents(int cnt[3])
{
	int smartest = -1;
	int tempCnt = -1;

	for (int i = 0; i < 3; i++)
	{
		if (tempCnt < cnt[i])
		{
			smartest = i + 1;
			tempCnt = cnt[i];
		}
	}

	vector<int> answer = { smartest };

	for (int i = 0; i < 3; i++)
	{
		if (smartest == i + 1 || tempCnt != cnt[i])
		{
			continue;
		}

		answer.push_back(i + 1);
	}

	sort(answer.begin(), answer.end());

	return answer;
}

vector<int> solution(vector<int> answers) {
	init();
	
	int idx[3] = { 0, 0, 0 };
	int cnt[3] = { 0, 0, 0 };

	for (int answer : answers)
	{
		for (int j = 0; j < 3; j++)
		{
			if (answer == students[j][idx[j]++])
			{
				cnt[j]++;
			}

			if (idx[j] == students[j].size())
			{
				idx[j] = j == 1 ? 1 : 0;
			}
		}
	}

	return getSmartestStudents(cnt);
}

int main(void)
{
	vector<int> answers = { 1, 2, 3, 4, 5 };

	vector<int> participants = solution(answers);

	for (int participant : participants)
	{
		cout << participant << " ";
	}

	cout << "\n";

	return 0;
}