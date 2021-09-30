
#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

int solution(string skill, vector<string> skill_trees) {
	int answer = 0;
	map<char, int> skill2idx;

	for (int i = 0; i < skill.length(); i++)
	{
		skill2idx[skill[i]] = i + 1;
	}

	for (string skillTree : skill_trees)
	{
		int idx = 1;
		bool flag = true;

		for (char c : skillTree)
		{
			if (skill2idx[c] > idx)
			{
				flag = false;

				break;
			}

			if (skill2idx[c] == idx)
			{
				idx++;
			}
		}

		if (flag)
		{
			answer++;
		}
	}

	return answer;
}

int main(void)
{
	string skill = "CBD";
	vector<string> skill_trees = { "BACDE", "CBADF", "AECB", "BDA" };

	cout << solution(skill, skill_trees) << "\n";

	return 0;
}