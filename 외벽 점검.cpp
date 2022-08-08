#include <string>
#include <vector>
#include <algorithm>
#include <climits>
#include <iostream>
using namespace std;

int solution(int n, vector<int> weak, vector<int> dist) {
	sort(dist.begin(), dist.end());

	int weakSize = weak.size();
	weak.resize(weakSize * 2);

	for (int i = 0; i < weakSize; i++)
	{
		weak[i + weakSize] = weak[i] + n;
	}

	int answer = INT_MAX;

	do
	{
		for (int i = 0; i < weakSize; i++)
		{
			int left = weak[i];
			int right = weak[i + weakSize - 1];
			int idx = i;

			for (int j = 0; j < dist.size(); j++)
			{
				if (left + dist[j] >= right)
				{
					answer = min(answer, j + 1);

					break;
				}

				for (int k = idx + 1; ; k++)
				{
					if (left + dist[j] < weak[k])
					{
						left = weak[k];
						idx = k;

						break;
					}
				}
			}
		}
	} while (next_permutation(dist.begin(), dist.end()));

	return answer == INT_MAX ? -1 : answer;
}
