#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

string solution(vector<string> participant, vector<string> completion) {
	map<string, int> visited;

	for (string c : completion)
	{
		visited[c]++;
	}

	for (string p : participant)
	{
		visited[p]--;
	}

	for (pair<string, int> runner : visited)
	{
		if (runner.second)
		{
			return runner.first;
		}
	}
}

int main(void)
{
	vector<string> participant = { "leo", "kiki", "eden" };
	vector<string> completion = { "eden", "kiki" };

	cout << solution(participant, completion) << "\n";

	return 0;
}