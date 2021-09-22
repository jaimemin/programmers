#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

typedef struct
{
	int time;
	int duration;
} Job;

bool operator<(Job a, Job b)
{
	return a.duration > b.duration;
}

bool cmp(const Job a, const Job b)
{
	return a.time < b.time;
}

int solution(vector<vector<int>> jobs) {
	priority_queue<Job> pq;
	vector<Job> jobArray;

	for (int i = 0; i < jobs.size(); i++)
	{
		jobArray.push_back({ jobs[i][0], jobs[i][1] });
	}

	sort(jobArray.begin(), jobArray.end(), cmp);

	int idx = 0;
	int sec = 0;
	int sum = 0;

	while (1)
	{
		while (idx != jobs.size())
		{
			int time = jobArray[idx].time;

			if (time > sec)
			{
				break;
			}

			pq.push(jobArray[idx++]);
		}

		if (pq.empty())
		{
			if (idx == jobs.size())
			{
				break;
			}

			sec++;

			continue;
		}

		Job cur = pq.top();
		pq.pop();

		sec += cur.duration;
		sum += (sec - cur.time);
	}

	return sum / jobs.size();
}

int main(void)
{
	vector<vector<int>> jobs = {
		{0, 3},
		{1, 9},
		{2, 6}
	};

	cout << solution(jobs) << "\n";

	return 0;
}