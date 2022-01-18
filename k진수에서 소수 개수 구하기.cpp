#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

string convert(int n, int k)
{
	string result;

	while (n)
	{
		result += to_string(n % k);

		n /= k;
	}

	reverse(result.begin(), result.end());

	return result;
}

bool isPrime(string temp)
{
	if (temp.empty() || temp == "1")
	{
		return false;
	}

	long long number = stol(temp);

	for (long long i = 2; i <= sqrt(number); i++)
	{
		if (number % i == 0)
		{
			return false;
		}
	}

	return true;
}

int solution(int n, int k) {
	string s = convert(n, k);
	string temp;

	int answer = 0;

	for (char c : s)
	{
		if (c == '0')
		{
			if (!temp.empty()
				&& isPrime(temp))
			{
				answer++;
			}

			temp = "";

			continue;
		}

		temp += c;
	}

	if (!temp.empty()
		&& isPrime(temp))
	{
		answer++;
	}

	return answer;
}