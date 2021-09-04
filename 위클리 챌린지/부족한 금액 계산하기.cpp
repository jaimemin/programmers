#include <iostream>
#include <algorithm>
using namespace std;

long long solution(int price, int money, int count)
{
	long long answer = 0;
	long long result = money - price * 1LL * (count * 1LL * (count + 1) * 1LL / 2);

	return max(answer, result * -1);
}

int main(void)
{
	cout << solution(2500, 1000000000, 2500) << "\n";

	return 0;
}
