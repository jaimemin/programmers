#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

long long solution(int n, vector<int> works) {
	priority_queue<long long> pq;

	for (int work : works)
	{
		pq.push(work);
	}

	for (int i = 0; i < n; i++)
	{
		long long cur = pq.top();
		pq.pop();

		pq.push(max(0LL, cur - 1));
	}

	long long answer = 0;

	while (!pq.empty())
	{
		answer += pq.top() * pq.top();
		pq.pop();
	}

	return answer;
}