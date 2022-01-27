#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;

string solution(int n) {
	string answer = "";

	while (n)
	{
		if (n % 3 == 0)
		{
			answer += '3';

			n -= 3;
		}
		else
		{
			answer += (n % 3) + '0';
		}

		n /= 3;
	}

	reverse(answer.begin(), answer.end());

	for (int i = 0; i < answer.size(); i++)
	{
		answer[i] = pow(2, answer[i] - '0' - 1) + '0';
	}

	return answer;
}