#include <iostream>
#include <string>
#include <vector>
using namespace std;

int getRank(int sum)
{
	switch (sum)
	{
	case 6:
		return 1;
	case 5:
		return 2;
	case 4:
		return 3;
	case 3:
		return 4;
	case 2:
		return 5;
	default:
		return 6;
	}
}

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
	int match = 0;
	int zero = 0;

	for (int i = 0; i < lottos.size(); i++)
	{
		zero += !lottos[i];
		
		for (int j = 0; j < win_nums.size(); j++)
		{
			match += (lottos[i] == win_nums[j]);
		}
	}
	
	return { getRank(match + zero), getRank(match) };
}

int main(void)
{
	vector<int> lottos = { 44, 1, 0, 0, 31, 25 };
	vector<int> win_nums = { 31, 10, 45, 1, 6, 19 };

	vector<int> answers = solution(lottos, win_nums);

	for (int answer : answers)
	{
		cout << answer << " ";
	}
	
	cout << "\n";

	return 0;
}