#include <string>
#include <vector>
#include <set>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 8;

int N;

set<string> result;

vector<int> v[MAX];

bool isIdentical(string userId, string bannedId)
{
	if (userId.length() != bannedId.length())
	{
		return false;
	}

	for (int i = 0; i < userId.length(); i++)
	{
		if (bannedId[i] != '*' && userId[i] != bannedId[i])
		{
			return false;
		}
	}

	return true;
}

void func(int idx, string s, set<int> visited)
{
	if (idx == N)
	{
		sort(s.begin(), s.end());
		result.insert(s);

		return;
	}

	for (int nameIdx : v[idx])
	{
		if (visited.find(nameIdx) == visited.end())
		{
			char c = nameIdx + '0';

			visited.insert(nameIdx);
			func(idx + 1, s + c, visited);
			visited.erase(nameIdx);
		}
	}
}

int solution(vector<string> user_id, vector<string> banned_id) {
	N = banned_id.size();

	for (int i = 0; i < banned_id.size(); i++)
	{
		for (int j = 0; j < user_id.size(); j++)
		{
			if (isIdentical(user_id[j], banned_id[i]))
			{
				v[i].push_back(j);
			}
		}
	}

	set<int> visited;

	func(0, "", visited);

	return result.size();
}