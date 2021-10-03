#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

int solution(int n) {
	string s;

	while (n)
	{
		s += (n % 3) + '0';

		n /= 3;
	}

	bool nonNecessaryZero = (s[0] == '0');

	if (nonNecessaryZero)
	{
		int idx = 1;

		for (int i = 1; i < s.length(); i++)
		{
			if (s[i] == '0')
			{
				continue;
			}

			idx = i;

			break;
		}

		s = s.substr(idx);
	}

	int answer = 0;

	for (int i = s.length() - 1; i >= 0; i--)
	{
		answer += (s[i] - '0') * pow(3, s.length() - (i + 1));
	}

	return answer;
}