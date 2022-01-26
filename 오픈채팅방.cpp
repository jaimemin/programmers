#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;

typedef struct
{
	bool isEnter;
	string uid;
} User;

vector<string> solution(vector<string> record) {
	map<string, string> uid2nickname;
	vector<User> chatHistories;

	for (int idx = 0; idx < record.size(); idx++)
	{
		string temp;
		string uid;
		int tempIdx = 0;
		bool isEnter;
		bool isChange = false;

		for (char c : record[idx])
		{
			if (c == ' ')
			{
				if (tempIdx == 0)
				{
					isEnter = temp == "Enter";
					isChange = temp == "Change";
				}
				else
				{
					uid = temp;
				}

				tempIdx++;
				temp = "";

				continue;
			}

			temp += c;
		}

		if (tempIdx == 1)
		{
			uid = temp;
		}
		else
		{
			uid2nickname[uid] = temp;
		}

		if (isChange == false)
		{
			chatHistories.push_back({ isEnter, uid });
		}
	}

	vector<string> answer;

	for (User user : chatHistories)
	{
		string s = uid2nickname[user.uid];
		s += "님이 ";
		s += user.isEnter ? "들어왔습니다." : "나갔습니다.";

		answer.push_back(s);
	}

	return answer;
}