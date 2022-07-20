#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

const int MAX = 360000;

long long arr[MAX];

int convertTimeToSeconds(string s)
{
	int hour = stoi(s.substr(0, 2)) * 3600;
	int minute = stoi(s.substr(3, 2)) * 60;
	int second = stoi(s.substr(6, 2));

	return hour + minute + second;
}

string convertSecondsToTime(int time)
{
	int hour = time / 3600;
	int minute = (time % 3600) / 60;
	int second = (time % 3600) % 60;
	string result = (hour < 10 ? "0" + to_string(hour) : to_string(hour))
		+ ":"
		+ (minute < 10 ? "0" + to_string(minute) : to_string(minute))
		+ ":"
		+ (second < 10 ? "0" + to_string(second) : to_string(second));

	return result;
}

string solution(string play_time, string adv_time, vector<string> logs) {
	if (play_time == adv_time)
	{
		return "00:00:00";
	}

	for (string log : logs)
	{
		string start = log.substr(0, 8);
		string end = log.substr(9, 8);
		int startTime = convertTimeToSeconds(start);
		int endTime = convertTimeToSeconds(end);

		for (int t = startTime + 1; t <= endTime; t++)
		{
			arr[t]++;
		}
	}

	string answer = convertSecondsToTime(0);
	int adTime = convertTimeToSeconds(adv_time);
	long long watchTime = 0;

	for (int t = 0; t <= adTime; t++)
	{
		watchTime += arr[t];
	}

	long long temp = watchTime;
	int maxTime = convertTimeToSeconds(play_time);

	for (int t = 1, t2 = adTime + 1; t2 <= maxTime; t++, t2++)
	{
		temp -= arr[t];
		temp += arr[t2];

		if (temp > watchTime)
		{
			answer = convertSecondsToTime(t);

			watchTime = temp;
		}
	}

	return answer;
}
