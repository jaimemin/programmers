#include <string>
#include <vector>

using namespace std;

bool solution(int x) {
	int copyX = x;
	int sum = 0;

	while (copyX)
	{
		sum += copyX % 10;

		copyX /= 10;
	}

	return !(x % sum);
}