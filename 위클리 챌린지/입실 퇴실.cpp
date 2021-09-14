#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
using namespace std;

vector<int> solution(vector<int> enter, vector<int> leave) {
	vector<int> answer(enter.size());

	int enterIdx = 0;
	int leaveIdx = 0;

	set<int> meetingRoom;
	map<pair<int, int>, bool> visited;

	while (leaveIdx < enter.size())
	{
		// ���� ���ʿ� �ִ� ����� ���� ȸ�ǽǿ� ������ �ʾ��� ���
		while (meetingRoom.find(leave[leaveIdx]) == meetingRoom.end())
		{
			int enterPerson = enter[enterIdx++];
			meetingRoom.insert(enterPerson);

			for (int person : meetingRoom)
			{
				visited[{person, enterPerson}] = true;
				visited[{enterPerson, person}] = true;
			}
		}

		// ȸ�ǽǿ� ���� ������ ����� �ִ� ���
		while (leaveIdx < enter.size() 
			&& meetingRoom.find(leave[leaveIdx]) != meetingRoom.end())
		{
			meetingRoom.erase(leave[leaveIdx++]);
		}
	}

	for (int i = 0; i < enter.size(); i++)
	{
		int cnt = 0;

		for (int j = 0; j < enter.size(); j++)
		{
			if (i == j)
			{
				continue;
			}

			if (visited.count({ enter[i], enter[j] }))
			{
				cnt++;
			}
		}

		answer[enter[i] - 1] = cnt;
	}
	
	return answer;
}

int main(void)
{
	vector<int> enter = { 1, 4, 2, 3 };
	vector<int> leave = { 2, 1, 3, 4 };

	vector<int> answers = solution(enter, leave);

	for (int answer : answers)
	{
		cout << answer << " ";
	}

	cout << "\n";

	return 0;
}