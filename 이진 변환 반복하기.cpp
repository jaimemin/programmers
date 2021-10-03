#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(string s) {
	int cnt = 0, zeroCnt = 0;

	while (s != "1")
	{
		string temp;

		for (char c : s)
		{
			if (c == '0')
			{
				zeroCnt++;
			}
			else
			{
				temp += c;
			}
		}

		int N = temp.length();
		s = "";

		while (N)
		{
			s += (N % 2) + '0';

			N /= 2;
		}

		reverse(s.begin(), s.end());
		cnt++;
	}

	return { cnt, zeroCnt };
}