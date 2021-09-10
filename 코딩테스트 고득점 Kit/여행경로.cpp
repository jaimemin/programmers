#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
using namespace std;

const string START = "ICN";

typedef struct
{
	string code;
	int idx;
} Airport;

bool cmp(Airport a, Airport b)
{
	return a.code < b.code;
}

int answerSize;
map<string, vector<Airport>> airports;
vector<string> paths;

void func(vector<string> answers, map<int, bool> visited)
{
	if (answers.size() == answerSize)
	{
		if (paths.empty()) // 최적의 답을 구하기 위해
		{
			paths = answers;
		}
	}

	for (Airport airport : airports[answers.back()])
	{
		if (visited[airport.idx])
		{
			continue;
		}

		visited[airport.idx] = true;
		answers.push_back(airport.code);
		func(answers, visited);
		answers.pop_back();
		visited[airport.idx] = false;
	}
}

vector<string> solution(vector<vector<string>> tickets) {
	answerSize = tickets.size() + 1;

	int idx = 0;
	
	for (int i = 0; i < tickets.size(); i++)
	{
		string source = tickets[i][0];
		string destination = tickets[i][1];

		airports[source].push_back({ destination, idx++ });
		sort(airports[source].begin(), airports[source].end(), cmp);
	}

	vector<string> answers;
	answers.push_back(START);

	map<int, bool> visited;

	func(answers, visited);

	return paths;
}

int main(void)
{
	vector<vector<string>> tickets = {
		{"ICN", "SFO"},
		{"ICN", "ATL"},
		{"SFO", "ATL"},
		{"ATL", "ICN"},
		{"ATL", "SFO"}
	};

	vector<string> answers = solution(tickets);

	for (string answer : answers)
	{
		cout << answer << " ";
	}

	cout << "\n";

	return 0;
}