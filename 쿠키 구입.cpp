#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 2000;

int cache[MAX][MAX];

int solution(vector<int> cookie) {
	for (int i = 0; i < cookie.size(); i++)
	{
		cache[i][i] = cookie[i];

		for (int j = i + 1; j < cookie.size(); j++)
		{
			cache[i][j] = cache[i][j - 1] + cookie[j];
		}
	}

	int answer = 0;

	for (int len = 0; len < cookie.size(); len++)
	{
		for (int i = 0; i < cookie.size() - (len + 1); i++)
		{
			int left = i + len + 1;
			int right = cookie.size();

			while (left <= right)
			{
				int mid = (left + right) / 2;

				if (cache[i][i + len] == cache[i + len + 1][mid])
				{
					answer = max(answer, cache[i][i + len]);

					break;
				}

				if (cache[i][i + len] > cache[i + len + 1][mid])
				{
					left = mid + 1;
				}
				else
				{
					right = mid - 1;
				}
			}
		}
	}

	return answer;
}

int main(void)
{
	vector<int> cookie = { 1, 1, 2, 3 };

	cout << solution(cookie) << "\n";

	return 0;
}