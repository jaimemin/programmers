#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
	vector<int> answer;

	for (int c = 0; c < commands.size(); c++)
	{
		int i = commands[c][0];
		int j = commands[c][1];
		int k = commands[c][2];

		vector<int> tempArray = array;

		sort(tempArray.begin() + i - 1, tempArray.begin() + j);

		answer.push_back(tempArray[i + k - 2]);
	}

	return answer;
}

int main(void)
{
	vector<int> array = { 1, 5, 2, 6, 3, 7, 4 };
	vector<vector<int>> commands = {
		{2, 5, 3},
		{4, 4, 1},
		{1, 7, 3}
	};

	vector<int> answers = solution(array, commands);

	for (int answer : answers)
	{
		cout << answer << " ";
	}

	cout << "\n";

	return 0;
}