#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 500 + 1;

pair<int, int> statistics[MAX];

bool cmp(pair<double, int> a, pair<double, int> b)
{
	if (a.first > b.first)
	{
		return true;
	}

	if (a.first == b.first)
	{
		if (a.second < b.second)
		{
			return true;
		}
	}

	return false;
}

vector<int> solution(int N, vector<int> stages) {
	for (int stage : stages)
	{
		for (int i = 1; i <= stage; i++)
		{
			statistics[i].second++;
		}

		statistics[stage].first++;
	}

	vector<pair<double, int>> failureRates;

	for (int i = 1; i <= N; i++)
	{
		if (statistics[i].first == 0)
		{
			failureRates.push_back({ 0, i });
		}
		else
		{
			failureRates.push_back({ double(statistics[i].first) / double(statistics[i].second), i });
		}
	}

	sort(failureRates.begin(), failureRates.end(), cmp);

	vector<int> answer;

	for (pair<double, int> ratio : failureRates)
	{
		answer.push_back(ratio.second);
	}

	return answer;
}