#include <iostream>
#include <cmath>
using namespace std;

int solution(int n, int a, int b)
{
	a--, b--;

	for (int round = 1; round <= log2(n); round++)
	{
		a /= 2;
		b /= 2;

		if (a == b)
		{
			return round;
		}
	}
}

int main(void)
{
	int N = 8;
	int A = 4;
	int B = 7;

	cout << solution(N, A, B) << "\n";

	return 0;
}