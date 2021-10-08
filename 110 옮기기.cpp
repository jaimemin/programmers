#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool isOneOneZero(string temp)
{
	return temp[temp.length() - 3] == '1'
		&& temp[temp.length() - 2] == '1'
		&& temp[temp.length() - 1] == '0';
}

vector<string> solution(vector<string> s) {
	vector<string> answer;

	for (string number : s)
	{
		if (number.length() <= 3)
		{
			answer.push_back(number);

			continue;
		}

		int len = number.length();
		int oneOneZeroCnt = 0;
		string temp;

		for (int i = 0; i < len; i++)
		{
			temp += number[i];
			int tempLength = temp.length();

			if (tempLength < 3)
			{
				continue;
			}

			if (isOneOneZero(temp))
			{
				temp.erase(tempLength - 3);

				oneOneZeroCnt++;
			}
		}

		int lastZeroIdx = -1;

		for (int i = temp.length() - 1; i >= 0; i--)
		{
			if (temp[i] == '0')
			{
				lastZeroIdx = i;

				break;
			}
		}

		string prefix = temp.substr(0, lastZeroIdx == -1 ? 0 : lastZeroIdx + 1);
		string suffix = lastZeroIdx != -1 ? temp.substr(lastZeroIdx + 1) : temp.substr(0);
		string result = prefix;

		for (int i = 0; i < oneOneZeroCnt; i++)
		{
			result += "110";
		}

		result += suffix;

		answer.push_back(result);
	}

	return answer;
}