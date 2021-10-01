#include <iostream>
#include <vector>
using namespace std;

int solution(int n, vector<int> stations, int w)
{
	vector<pair<int, int>> notReachedRanges;
	int start = 1;

	for (int station : stations)
	{
		if (start < station - w)
		{
			notReachedRanges.push_back({ start, station - w - 1 });
		}

		start = station + w + 1;
	}

	if (start <= n)
	{
		notReachedRanges.push_back({ start, n });
	}

	int answer = 0;
	int radioWave = 2 * w + 1;
	
	for (pair<int, int> range : notReachedRanges)
	{
		int len = range.second - range.first + 1;

		if (len <= radioWave)
		{
			answer++;
		}
		else
		{
			answer += len / radioWave + (len % radioWave != 0);
		}
	}

	return answer;
}