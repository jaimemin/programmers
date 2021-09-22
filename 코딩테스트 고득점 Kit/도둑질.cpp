#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> money) {
	vector<long long> startFromZero(money.size(), money[0]);
	vector<long long> startFromOne(money.size(), money[1]);

	for (int i = 2; i <= money.size() - 2; i++)
	{
		startFromZero[i] = max(startFromZero[i - 1], startFromZero[i - 2] + money[i]);
	}

	startFromOne[0] = 0;

	for (int i = 2; i <= money.size() - 1; i++)
	{
		startFromOne[i] = max(startFromOne[i - 1], startFromOne[i - 2] + money[i]);
	}

	return max(startFromZero[money.size() - 2], startFromOne[money.size() - 1]);
}

int main(void)
{
	vector<int> money = { 1, 2, 3, 1 };

	cout << solution(money) << "\n";

	return 0;
}