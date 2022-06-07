#include <string>
#include <vector>
using namespace std;

vector<vector<int>> answer;

void Hanoi(int num, int from, int by, int to)
{
	if (num == 1)
	{
		answer.push_back({ from, to });
	}
	else
	{
		Hanoi(num - 1, from, to, by);
		answer.push_back({ from, to });
		Hanoi(num - 1, by, from, to);
	}
}

vector<vector<int>> solution(int n) {
	Hanoi(n, 1, 2, 3);

	return answer;
}