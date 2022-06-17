#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, int s) {
	if (s / n == 0) {
		return { -1 };
	}

	vector<int> answer;

	for (int i = 0; i < n; i++)
	{
		answer.push_back(s / n);
	}

	int total = (s / n) * n;

	for (int i = 0; i < s - total; i++)
	{
		answer[n - (i + 1)]++;
	}

	return answer;
}