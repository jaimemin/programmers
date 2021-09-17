#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

typedef struct
{
	int priority;
	int idx;
} Document;

const int MAX = 10;

int solution(vector<int> priorities, int location) {
	
	int morePriority[MAX] = { 0, };
	queue<Document> q;

	for (int i = 0; i < priorities.size(); i++)
	{
		for (int j = 1; j < priorities[i]; j++)
		{
			morePriority[j]++;
		}

		q.push({ priorities[i], i });
	}

	int answer = 0;

	while (!q.empty())
	{
		Document cur = q.front();
		q.pop();

		if (morePriority[cur.priority])
		{
			q.push(cur);

			continue;
		}

		answer++;

		for (int j = 1; j < cur.priority; j++)
		{
			morePriority[j]--;
		}

		if (cur.idx == location)
		{
			return answer;
		}
	}
}

int main(void)
{
	vector<int> priorities = { 2, 1, 3, 2 };
	int location = 2;

	cout << solution(priorities, location) << "\n";

	return 0;
}