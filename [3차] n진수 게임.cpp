#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

string getJinbub(int num, int n)
{
	string result;

	while (num)
	{
		int temp = num % n;

		if (temp >= 10)
		{
			char c = 'A';

			result += string(1, c + temp - 10);
		}
		else
		{
			result += (temp + '0');
		}

		num /= n;
	}

	reverse(result.begin(), result.end());

	return result.empty() ? "0" : result;
}

string solution(int n, int t, int m, int p) {
	string answer = "";
	int cnt = 0;
	int num = 0;
	int turn = 0;
	p--;

	while (1)
	{
		string temp = getJinbub(num++, n);

		for (char c : temp)
		{
			if (turn == p)
			{
				answer += c;

				if (++cnt == t)
				{
					return answer;
				}
			}

			turn = (turn + 1) % m;
		}
	}
}

int main(void)
{
	cout << solution(2, 4, 2, 1) << "\n";

	return 0;
}