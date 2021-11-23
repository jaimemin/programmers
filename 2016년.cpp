#include <string>
#include <vector>
using namespace std;

const int WEEK = 7;

int month[13] = { 0, 0, 31, 60, 91, 121, 152, 182, 213, 244, 274, 305, 335 };

string solution(int a, int b) {
	int mod = month[a] + b - 1;
	mod %= WEEK;

	string answer;

	switch (mod)
	{
	case 0:
		answer = "FRI";

		break;
	case 1:
		answer = "SAT";

		break;
	case 2:
		answer = "SUN";

		break;
	case 3:
		answer = "MON";

		break;
	case 4:
		answer = "TUE";

		break;
	case 5:
		answer = "WED";

		break;
	case 6:
		answer = "THU";

		break;
	}

	return answer;
}