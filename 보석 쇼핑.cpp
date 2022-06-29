#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
using namespace std;

const int MAX = 1e5;

vector<int> solution(vector<string> gems) {
	set<string> visited;

	for (string gem : gems)
	{
		visited.insert(gem);
	}

	int gemCnt = visited.size();
	int gemSize = gems.size();

	int start = 0, end = 0;
	pair<int, int> answer = { 1, gemSize };

	set<string> curGems;
	map<string, int> curGemsCnt;
	curGems.insert(gems[0]);
	curGemsCnt[gems[0]]++;

	while (start <= end && end < gemSize)
	{
		if (gemCnt == curGems.size())
		{
			if (answer.second - answer.first > end - start)
			{
				answer = { start + 1, end + 1 };
			}

			if (--curGemsCnt[gems[start]] == 0)
			{
				curGems.erase(gems[start]);
			}

			start++;
		}
		else if (gemCnt > curGems.size())
		{
			if (++end >= gemSize)
			{
				break;
			}

			curGems.insert(gems[end]);
			curGemsCnt[gems[end]]++;
		}
	}

	return { answer.first, answer.second };
}