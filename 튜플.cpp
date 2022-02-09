#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b)
{
	return a.second > b.second;
}

vector<int> solution(string s) {
	set<int> tupleSet;
	map<int, int> visited;
	string temp;

	for (char c : s)
	{
		if (c == '{' || c == '}' || c == ',')
		{
			if (!temp.empty())
			{
				tupleSet.insert(stoi(temp));
				visited[stoi(temp)]++;

				temp.clear();
			}

			continue;
		}

		temp += c;
	}

	vector<pair<int, int>> v;

	for (auto t : tupleSet)
	{
		v.push_back({ t, visited[t] });
	}

	sort(v.begin(), v.end(), cmp);

	vector<int> answer;

	for (pair<int, int> a : v)
	{
		answer.push_back(a.first);
	}

	return answer;
}