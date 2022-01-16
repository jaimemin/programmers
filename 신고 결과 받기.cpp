#include <string>
#include <vector>
#include <map>
#include <set>
using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
	map<string, set<string>> reportMap;
	map<string, int> reportCnt;

	for (string s : report)
	{
		string temp;
		string reporter;

		for (char c : s)
		{
			if (c == ' ')
			{
				reporter = temp;
				temp = "";

				continue;
			}

			temp += c;
		}

		if (reportMap[reporter].count(temp))
		{
			continue;
		}

		reportMap[reporter].insert(temp);
		reportCnt[temp]++;
	}

	vector<int> answer(id_list.size());
	set<string> visited;

	for (string id : id_list)
	{
		if (reportCnt[id] < k)
		{
			continue;
		}

		visited.insert(id);
	}

	for (int i = 0; i < id_list.size(); i++)
	{
		int cnt = 0;

		for (auto r : reportMap[id_list[i]])
		{
			if (visited.find(r) != visited.end())
			{
				cnt++;
			}
		}

		answer[i] = cnt;
	}

	return answer;
}