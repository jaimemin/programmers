#include <iostream>
using namespace std;

int solution(int n)
{
	int answer = 0;

	while (n)
	{
		n = n % 2 ? n - 1, answer++ : n / 2;
	}

	return answer;
}

int main(void)
{
	int N = 5;

	cout << solution(N) << "\n";

	return 0;
}