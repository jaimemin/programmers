#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

const int HOUR_TO_SECOND = 3600;

const int MINUTE_TO_SECOND = 60;

const int SECOND = 1000;

vector<pair<int, int>> orders;

int solution(vector<string> lines) {
	for (string line : lines)
	{
		int hour = stoi(line.substr(11, 2)) * HOUR_TO_SECOND * 1000;
		int minute = stoi(line.substr(14, 2)) * MINUTE_TO_SECOND * 1000;
		int second = stoi(line.substr(17, 2)) * 1000;
		int ms = stoi(line.substr(20, 3));
		int duration = (int)(stod(line.substr(24)) * 1000) - 1;
		
		int time = hour + minute + second + ms;

		orders.push_back({ time - duration, time });
	}

	int result = 1;

	for (int i = 0; i < orders.size(); i++)
	{
		int endTime = orders[i].second + SECOND;
		int cnt = 1;

		for (int j = i + 1; j < orders.size(); j++)
		{
			int curStartTime = orders[j].first;

			if (curStartTime < endTime)
			{
				cnt++;
			}
		}

		result = max(result, cnt);
	}

	return result;
}

int main(void)
{
	vector<string> lines = { "2016-09-15 20:59:57.421 0.351s"
		, "2016-09-15 20:59:58.233 1.181s"
		, "2016-09-15 20:59:58.299 0.8s"
		, "2016-09-15 20:59:58.688 1.041s"
		, "2016-09-15 20:59:59.591 1.412s"
		, "2016-09-15 21:00:00.464 1.466s"
		, "2016-09-15 21:00:00.741 1.581s"
		, "2016-09-15 21:00:00.748 2.31s"
		, "2016-09-15 21:00:00.966 0.381s"
		, "2016-09-15 21:00:02.066 2.62s" };

	cout << solution(lines) << "\n";

	return 0;
}