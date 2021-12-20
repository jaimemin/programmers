#include <string>
#include <vector>
using namespace std;

bool solution(string s) {
	if (!(s.length() == 4 || s.length() == 6))
	{
		return false;
	}

	for (char c : s)
	{
		if (c < '0' || c > '9')
		{
			return false;
		}
	}

	return true;
}