#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#include <map>
#include <iostream>
using namespace std;

const string MAX_TO = "23:59";

typedef struct
{
	string from;
	string to;
} Time;

int getDiffMinute(string from, string to)
{
	int toHour = stoi(to.substr(0, 2));
	int toMinute = stoi(to.substr(3, 2));
	int fromHour = stoi(from.substr(0, 2));
	int fromMinute = stoi(from.substr(3, 2));

	return (toHour - fromHour) * 60 + (toMinute - fromMinute);
}

vector<int> solution(vector<int> fees, vector<string> records) {
	map<string, vector<Time>> carRecords;
	set<string> carNumbers;

	for (string record : records)
	{
		string temp;
		vector<string> v;

		for (char c : record)
		{
			if (c == ' ')
			{
				v.push_back(temp);
				temp = "";

				continue;
			}

			temp += c;
		}

		carNumbers.insert(v[1]);

		if (temp == "IN")
		{
			carRecords[v[1]].push_back({ v[0], "" });
		}
		else
		{
			for (int i = 0; i < carRecords[v[1]].size(); i++)
			{
				if (carRecords[v[1]][i].to == "")
				{
					carRecords[v[1]][i].to = v[0];

					break;
				}
			}
		}
	}

	vector<int> answer;

	for (string carNumber : carNumbers)
	{
		int diffMinute = 0;

		for (Time time : carRecords[carNumber])
		{
			if (time.to == "")
			{
				time.to = MAX_TO;
			}

			diffMinute += getDiffMinute(time.from, time.to);
		}

		int fee = fees[1] + ceil(max(diffMinute - fees[0], 0) / double(fees[2])) * fees[3];

		answer.push_back(fee);
	}

	return answer;
}