#include <string>
#include <vector>
#include <iostream>
#include <map>
using namespace std;

const int MAX = 10;

vector<int> solution(int n, vector<string> words) {
	map<string, bool> visited;
	string before = words[0];
	visited[before] = true;

	int idx = 1;
	int cnts[MAX] = { 0, };
	cnts[0] = 1;

	for (int i = 1; i < words.size(); i++)
	{
		if (visited.count(words[i]) 
			|| before.back() != words[i].front())
		{
			return { idx + 1, ++cnts[idx] };
		}

		visited[words[i]] = true;
		cnts[idx]++;

		idx = (idx + 1) % n;
		before = words[i];
	}

	return { 0, 0 };
}