#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

const int MAX = 8;

int rowSize, columnSize;

vector<string> columns[MAX];
bool visited[MAX];
vector<string> candidateKeys;

bool isCandidateKey(string candidates)
{
	vector<string> v(rowSize, "");

	for (char c : candidates)
	{
		for (int i = 0; i < rowSize; i++)
		{
			v[i] += columns[c - '0'][i];
		}
	}

	sort(v.begin(), v.end());

	for (int i = 0; i < v.size() - 1; i++)
	{
		if (v[i] == v[i + 1])
		{
			return false;
		}
	}

	return true;
}

bool isMinimum(string candidates, string candidateKey)
{
	int cnt = 0;

	for (char c : candidateKey)
	{
		for (char candidate : candidates)
		{
			if (c == candidate)
			{
				cnt++;

				break;
			}
		}
	}

	return cnt != candidateKey.size();
}

void func(string candidates, int prevIdx, int maxCnt)
{
	if (candidates.size() == maxCnt)
	{
		if (!isCandidateKey(candidates))
		{
			return;
		}

		bool flag = true;

		for (string candidateKey : candidateKeys)
		{
			if (!isMinimum(candidates, candidateKey))
			{
				flag = false;

				break;
			}
		}

		if (flag)
		{
			candidateKeys.push_back(candidates);
		}

		return;
	}

	if (prevIdx == columnSize - 1)
	{
		return;
	}

	for (int idx = prevIdx + 1; idx < columnSize; idx++)
	{
		candidates += (idx + '0');
		func(candidates, idx, maxCnt);
		candidates.pop_back();
	}
}

int solution(vector<vector<string>> relation) {
	rowSize = relation.size();
	columnSize = relation[0].size();

	for (vector<string> r : relation)
	{
		for (int i = 0; i < r.size(); i++)
		{
			columns[i].push_back(r[i]);
		}
	}

	for (int cnt = 1; cnt <= rowSize; cnt++)
	{
		func("", -1, cnt);
	}

	return candidateKeys.size();
}

int main(void)
{
	vector<vector<string>> relation = {
		{ "100","ryan","music","2" },
		{ "200","apeach","math","2" },
		{ "300","tube","computer","3" },
		{ "400","con","computer","4" },
		{ "500","muzi","music","3" },
		{ "600","apeach","music","2" }
	};

	cout << solution(relation) << "\n";

	return 0;
}