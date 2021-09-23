#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

const int ALPHA_MAX = 26;

int solution(string name) {
	string temp;

	for (int i = 0; i < name.length(); i++)
	{
		temp += "A";
	}

	int idx = 0;
	int answer = 0;

	while (temp != name)
	{
		for (int i = 0; i < name.length(); i++)
		{
			int next = (idx + i) % name.length();
			int before = (idx + name.length() - i) % name.length();

			if (temp[next] != name[next])
			{
				answer += i;
				idx = next;

				break;
			}

			if (temp[before] != name[before])
			{
				answer += i;
				idx = before;

				break;
			}
		}

		answer += min(name[idx] - temp[idx], (temp[idx] - name[idx]) + ALPHA_MAX);
		temp[idx] = name[idx];
	}

	return answer;
}

int main(void)
{
	string name = "ZZAAAZZ";

	cout << solution(name) << "\n";

	return 0;
}