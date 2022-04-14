#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

const int HOUR = 60;

bool canRideBus(string time, int busHour, int busMinute)
{
	int hour = stoi(time.substr(0, 2));
	int minute = stoi(time.substr(3, 2));

	return (busHour * 100 + busMinute) >= (hour * 100 + minute);
}

string convertTimeToString(int hour, int minute)
{
	string curHour = to_string(hour);
	string curMinute = to_string(minute);

	if (curHour.length() == 1)
	{
		curHour = "0" + curHour;
	}

	if (curMinute.length() == 1)
	{
		curMinute = "0" + curMinute;
	}

	return curHour + ":" + curMinute;
}

string getPastMinute(string time)
{
	int hour = stoi(time.substr(0, 2));
	int minute = stoi(time.substr(3, 2));
	minute--;

	if (minute < 0)
	{
		minute += HOUR;
		hour--;
	}

	return convertTimeToString(hour, minute);
}

string solution(int n, int t, int m, vector<string> timetable) {
	sort(timetable.begin(), timetable.end());

	int busHour = 9;
	int busMinute = 0;
	int rangeIdx = 0;
	int idx = 0;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (timetable.size() <= idx)
			{
				break;
			}

			if (canRideBus(timetable[idx], busHour, busMinute))
			{
				rangeIdx++;
				idx++;
			}
			else
			{
				break;
			}
		}

		if (i != n - 1)
		{
			busMinute += t;

			if (busMinute >= HOUR)
			{
				busMinute -= HOUR;
				busHour++;
			}

			rangeIdx = 0;
		}
	}

	if (idx == 0 || rangeIdx != m)
	{
		return convertTimeToString(busHour, busMinute);
	}

	return getPastMinute(timetable[idx - 1]);
}

int main(void)
{
	int n = 1;
	int t = 1;
	int m = 5;
	vector<string> timetable = { "00:01", "00:01", "00:01","00:01", "00:01", "00:02", "00:03", "00:04" };

	cout << solution(n, t, m, timetable) << "\n";

	return 0;
}