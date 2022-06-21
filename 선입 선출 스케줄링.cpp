#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
using namespace std;

const int MAX = 1e5;

int solution(int n, vector<int> cores) {
	if (n <= cores.size())
	{
		return n;
	}

	int size = cores.size();
	int minCore = MAX;
	int maxCore = 0;

	for (int core : cores)
	{
		minCore = min(minCore, core);
		maxCore = max(maxCore, core);
	}

	int left = (minCore * (n - size)) / size;
	int right = (maxCore * (n - size)) / size;

	while (left <= right)
	{
		int mid = (left + right) / 2;
		int workCnt = size;
		int curWorkCnt = 0;

		for (int core : cores)
		{
			workCnt += (mid / core);

			if (mid % core == 0)
			{
				curWorkCnt++;
			}
		}

		int diff = workCnt - curWorkCnt;

		if (n > workCnt)
		{
			left = mid + 1;
		}
		else if (diff >= n)
		{
			// diff > n이 아니라 diff >= n인 이유는 if (mid % cores[i] == 0)을 먼저 체크하기 때문에
			right = mid - 1;
		}
		else
		{
			for (int i = 0; i < size; ++i)
			{
				if (mid % cores[i] == 0)
				{
					diff++;
				}

				if (diff == n)
				{
					return i + 1;
				}
			}
		}
	}

	return 0;
}

int main(void)
{
	int n = 6;
	vector<int> cores = { 1, 2, 3 };

	cout << solution(n, cores) << "\n";

	return 0;
}
