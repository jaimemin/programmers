#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(string a, string b)
{
	string aConcatB = a + b;
	string bConcatA = b + a;

	return aConcatB > bConcatA;
}

string eraseLeadingZeros(string s)
{
	string result;
	bool isLeadingZero = true;

	for (char c : s)
	{
		if (c == '0' && isLeadingZero)
		{
			continue;
		}

		isLeadingZero = false;
		result += c;
	}

	return result;
}

string solution(vector<int> numbers) {
	vector<string> v;

	for (int number : numbers)
	{
		v.push_back(to_string(number));
	}

	sort(v.begin(), v.end(), cmp);

	string answer = "";

	for (string s : v)
	{
		answer += s;
	}

	string result = eraseLeadingZeros(answer);

	return result.length() ? result : "0";
}

int main(void)
{
	vector<int> numbers = { 21, 212 };

	cout << solution(numbers) << "\n";

	return 0;
}