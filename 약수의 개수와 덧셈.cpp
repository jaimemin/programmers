#include <string>
#include <vector>
using namespace std;

const int MAX = 1000 + 10;

bool visited[MAX];

int solution(int left, int right) {
	for (int i = 1; i * i < MAX; i++)
	{
		visited[i * i] = true;
	}

	int answer = 0;

	for (int i = left; i <= right; i++)
	{
		answer += (visited[i] ? -i : i);
	}

	return answer;
}