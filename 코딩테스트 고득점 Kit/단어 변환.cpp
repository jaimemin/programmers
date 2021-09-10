#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <map>
using namespace std;

typedef struct
{
	int cnt;
	string s;
} Word;

bool operator<(Word a, Word b)
{
	return a.cnt < b.cnt;
}

bool isOneCharacterDiff(string a, string b)
{
	int cnt = 0;

	for (int i = 0; i < a.length(); i++)
	{
		if (a[i] == b[i])
		{
			continue;
		}

		if (++cnt >= 2)
		{
			return false;
		}
	}

	return cnt == 1;
}

int solution(string begin, string target, vector<string> words) {
	priority_queue<Word> pq;
	pq.push({ 0, begin });

	map<string, bool> visited;
	visited[begin] = true;

	while (!pq.empty())
	{
		int cnt = pq.top().cnt;
		string s = pq.top().s;
		pq.pop();

		if (s == target)
		{
			return cnt;
		}

		for (string word : words)
		{
			if (!visited.count(word)
				&& isOneCharacterDiff(s, word))
			{
				visited[word] = true;
				pq.push({ cnt + 1, word });
			}
		}
	}

	return 0;
}

int main(void)
{
	string begin = "hit";
	string target = "cog";
	vector<string> words = { "hot", "dot", "dog", "lot", "log", "cog" };

	cout << solution(begin, target, words) << "\n";

	return 0;
}