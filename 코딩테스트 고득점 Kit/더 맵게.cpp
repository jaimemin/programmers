#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <functional>
using namespace std;

int solution(vector<int> scoville, int K) {
	int answer = 0;

	priority_queue<int, vector<int>, greater<int>> pq;

	bool allEqualOrOverK = true;

	for (int s : scoville)
	{
		if (s < K)
		{
			allEqualOrOverK = false;
		}

		pq.push(s);
	}

	if (allEqualOrOverK)
	{
		return 0;
	}

	int mixCnt = 0;

	while (!pq.empty())
	{
		int cur = pq.top();
		pq.pop();

		// 음식이 하나 남았고 조건을 충족하지 않을 경우
		if (pq.empty() && cur < K)
		{
			break;
		}

		int next = pq.top();
		pq.pop();

		mixCnt++;
		pq.push(cur + next * 2);
		
		allEqualOrOverK = true;
		vector<int> v;

		while (!pq.empty())
		{
			if (pq.top() < K)
			{
				allEqualOrOverK = false;

				break;
			}

			v.push_back(pq.top());
			pq.pop();
		}

		if (allEqualOrOverK)
		{
			return mixCnt;
		}

		for (int scoville : v)
		{
			pq.push(scoville);
		}
	}

	return -1;
}

int main(void)
{
	vector<int> scoville = { 1, 2, 3, 9, 10, 12 };
	int K = 7;

	cout << solution(scoville, K) << "\n";

	return 0;
}