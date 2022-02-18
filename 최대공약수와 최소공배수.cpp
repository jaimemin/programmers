#include <string>
#include <vector>
using namespace std;

int GCD(int a, int b)
{
	if (a % b == 0)
	{
		return b;
	}

	return GCD(b, a % b);
}

//최소 공배수
int LCM(int a, int b)
{
	return (a * b) / GCD(a, b);
}

vector<int> solution(int n, int m) {
	return { GCD(n, m), LCM(n, m) };
}