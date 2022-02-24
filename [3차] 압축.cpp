#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;

const int MAX = 26;

int visitedIdx = 1;
map<string, int> visited;

void init()
{
	char c = 'A';

	for (int i = 0; i < MAX; i++)
	{
		string temp(1, c++);
		visited[temp] = visitedIdx++;
	}
}

vector<int> solution(string msg) {
	init();

	vector<int> answer;

	for (int i = 0; i < msg.length(); i++)
	{
		string cur, next;

		for (int j = 0; j < msg.length() - i; j++)
		{
			cur = msg.substr(i, j + 1);
			next = msg.substr(i, j + 2);
			
			if (visited.count(cur))
			{
				if (cur == next)
				{
					answer.push_back(visited[cur]);
					i += j;

					break;
				}

				if (visited.count(next))
				{
					continue;
				}

				answer.push_back(visited[cur]);
				visited[next] = visitedIdx++;
				i += j;
				
				break;
			}
		}
	}

	return answer;
}

int main(void)
{
	vector<int> answer = solution("TOBEORNOTTOBEORTOBEORNOT");

	for (int a : answer)
	{
		cout << a << " ";
	}
	cout << "\n";

	return 0;
}