#include <string>
#include <vector>
using namespace std;

int solution(int n) {
	for (int x = 2; ; x++)
	{
		if (n % x == 1)
		{
			return x;
		}
	}
}