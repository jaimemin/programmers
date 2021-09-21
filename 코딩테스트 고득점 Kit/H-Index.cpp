#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(int a, int b)
{
	return a > b;
}

int solution(vector<int> citations) {
	sort(citations.begin(), citations.end(), cmp);

	int answer = 0;

	for (int h = citations[0]; h >= 1; h--)
	{
		int temp = 0;

		for (int citation : citations)
		{
			if (citation >= h)
			{
				temp++;
			}
		}

		if (temp >= h)
		{
			answer = h;

			break;
		}
	}

	return answer;
}

int main(void)
{
	vector<int> citations = { 0, 1, 1 };

	cout << solution(citations) << "\n";

	return 0;
}