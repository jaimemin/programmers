#include <string>
#include <vector>
using namespace std;

int getBinaryCnt(int n)
{
	int cnt = 0;

	while (n)
	{
		cnt = n % 2 ? cnt + 1 : cnt;

		n /= 2;
	}

	return cnt;
}

int solution(int n) {
	int cnt = getBinaryCnt(n);

	for (int num = n + 1; ; num++)
	{
		if (getBinaryCnt(num) == cnt)
		{
			return num;
		}
	}
}