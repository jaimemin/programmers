#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

const int MAX = 30;
vector<string> clothTypes[MAX];

int solution(vector<vector<string>> clothes) {
	map<string, int> clothType2idx;

	int idx = 0;

	for (int i = 0; i < clothes.size(); i++)
	{
		string cloth = clothes[i][0];
		string type = clothes[i][1];

		if (!clothType2idx.count(type))
		{
			clothType2idx[type] = idx++;
		}

		clothTypes[clothType2idx[type]].push_back(cloth);
	}

	int answer = 1;

	for (int i = 0; i < idx; i++)
	{
		answer *= (clothTypes[i].size() + 1);
	}

	return answer - 1;
}

int main(void)
{
	vector<vector<string>> clothes = {
		{ "yellowhat", "headgear" },
		{ "bluesunglasses", "eyewear" },
		{ "green_turban", "headgear" }
	};

	cout << solution(clothes) << "\n";

	return 0;
}