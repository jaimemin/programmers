#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

const int VISITED_MAX = 20 + 1;

const int MAX = 10 + 1;

int wordLengthCnts[MAX];
vector<string> menus[MAX][VISITED_MAX];
map<string, int> visited;

void func(int idx, string order, string word)
{
	if (word.size() >= 2)
	{
		visited[word]++;

		wordLengthCnts[word.size()] = max(wordLengthCnts[word.size()], visited[word]);
		menus[word.size()][visited[word]].push_back(word);
	}

	for (int i = idx + 1; i < order.size(); i++)
	{
		word.push_back(order[i]);
		func(i, order, word);
		word.pop_back();
	}
}

vector<string> solution(vector<string> orders, vector<int> course) {
	vector<string> answer;

	for (string order : orders)
	{
		sort(order.begin(), order.end());

		func(-1, order, "");
	}

	for (int c : course)
	{
		if (wordLengthCnts[c] < 2)
		{
			continue;
		}

		for (string s : menus[c][wordLengthCnts[c]])
		{
			answer.push_back(s);
		}
	}

	sort(answer.begin(), answer.end());

	return answer;
}