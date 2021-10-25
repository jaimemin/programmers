#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(int k, vector<vector<int>> dungeons) {
	vector<int> v;

	for (int i = 0;i < dungeons.size(); i++)
	{
		v.push_back(i);
	}

	int result = 0;

	do
	{
		int copyK = k;
		int cnt = 0;

		for (int i = 0; i < v.size(); i++)
		{
			int minHealth = dungeons[v[i]][0];
			int usedHealth = dungeons[v[i]][1];

			if (minHealth > copyK)
			{
				continue;
			}

			copyK -= usedHealth;
			cnt++;
		}

		result = max(result, cnt);
	} while (next_permutation(v.begin(), v.end()));

	return result;
}