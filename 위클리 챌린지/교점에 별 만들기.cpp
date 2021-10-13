#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

vector<string> solution(vector<vector<int>> line) {
	long long minX = LLONG_MAX, minY = LLONG_MAX;
	long long maxX = LLONG_MIN, maxY = LLONG_MIN;

	vector<pair<long long, long long>> coords;
	int lineSize = line.size();

	for (int i = 0; i < lineSize; i++)
	{
		for (int j = i + 1; j < lineSize; j++)
		{
			long long A = line[i][0], B = line[i][1], E = line[i][2];
			long long C = line[j][0], D = line[j][1], F = line[j][2];

			long long xNumerator = B * F * 1LL - E * D * 1LL;
			long long yNumerator = E * C * 1LL - A * F * 1LL;
			long long mod = A * D * 1LL - B * C * 1LL;

			if (mod == 0)
			{
				continue;
			}

			if (xNumerator % mod || yNumerator % mod)
			{
				continue;
			}

			long long x = xNumerator / mod;
			long long y = yNumerator / mod;

			minX = min(minX, x);
			minY = min(minY, y);

			maxX = max(maxX, x);
			maxY = max(maxY, y);

			coords.push_back({ x, y });
		}
	}

	string row = string(maxX - minX + 1, '.');
	vector<string> answer(maxY - minY + 1, row);

	for (pair<long long, long long> coord : coords)
	{
		answer[abs(coord.second - maxY)][abs(coord.first - minX)] = '*';
	}

	return answer;
}