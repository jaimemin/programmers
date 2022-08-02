#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int n, vector<vector<int>> data) {
	sort(data.begin(), data.end());

	int answer = 0;

	for (int i = 0; i < data.size() - 1; i++)
	{
		for (int j = i + 1; j < data.size(); j++)
		{
			pair<int, int> p = { data[i][0], data[i][1] };
			pair<int, int> p2 = { data[j][0], data[j][1] };

			if (p.first == p2.first || p.second == p2.second)
			{
				continue;
			}

			bool installable = true;

			for (int k = i + 1; k < j; k++)
			{
				pair<int, int> p3 = { data[k][0], data[k][1] };

				if ((p.first < p3.first && p3.first < p2.first)
					&& min(p.second, p2.second) < p3.second
					&& max(p.second, p2.second) > p3.second)
				{
					installable = false;

					break;
				}
			}

			answer += installable ? 1 : 0;
		}
	}

	return answer;
}