#include <iostream>
#include <string>
#include <vector>
using namespace std;

const int MAX = 200 + 20;

bool visited[MAX];

void func(int idx, int n, vector<vector<int>> computers)
{
	for (int i = 0; i < n; i++)
	{
		if (idx == i 
			|| visited[i] 
			|| computers[idx][i] == 0)
		{
			continue;
		}

		visited[i] = true;
		func(i, n, computers);
	}
}

int solution(int n, vector<vector<int>> computers) {
	int answer = 0;

	for (int i = 0; i < n; i++)
	{
		if (visited[i])
		{
			continue;
		}

		answer++;
		visited[i] = true;
		func(i, n, computers);
	}

	return answer;
}

int main(void)
{
	vector<vector<int>> computers = {
		{ 1, 1, 0 }, 
		{ 1, 1, 0 },
		{ 0, 0, 1 }
	};

	cout << solution(3, computers) << "\n";

	return 0;
}