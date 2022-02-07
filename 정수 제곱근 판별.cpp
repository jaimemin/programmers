#include <string>
#include <vector>
#include <cmath>
using namespace std;

long long solution(long long n) {
	double num = sqrt(n);

	if (num == floor(num))
	{
		return (num + 1) * (num + 1);
	}

	return -1;
}