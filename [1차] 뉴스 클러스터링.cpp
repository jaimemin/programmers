#include <string>
#include <algorithm>
#include <map>
#include <set>
#include <iostream>
using namespace std;

const int MULTIPLE = 65536;

bool isAlphabet(char c)
{
	return (c >= 'A' && c <= 'Z')
		|| (c >= 'a' && c <= 'z');
}

string convertToLowercase(string s)
{
	string result;

	for (char c : s)
	{
		result += c >= 'A' && c <= 'Z' ? c - 'A' + 'a' : c;
	}

	return result;
}

int solution(string str1, string str2) {
	map<string, int> visited, visited2;
	set<string> keys;

	for (int i = 0; i < str1.length() - 1; i++)
	{
		if (!(isAlphabet(str1[i]) && isAlphabet(str1[i + 1])))
		{
			continue;
		}

		string temp = convertToLowercase(str1.substr(i, 2));
		visited[temp]++;
		keys.insert(temp);
	}

	for (int i = 0; i < str2.length() - 1; i++)
	{
		if (!(isAlphabet(str2[i]) && isAlphabet(str2[i + 1])))
		{
			continue;
		}

		string temp = convertToLowercase(str2.substr(i, 2));
		visited2[temp]++;
		keys.insert(temp);
	}

	double numerator = 0, denominator = 0;

	for (auto key : keys)
	{
		numerator += min(visited[key], visited2[key]);
		denominator += max(visited[key], visited2[key]);
	}

	if (!numerator && !denominator)
	{
		return MULTIPLE;
	}

	double result = numerator / denominator * MULTIPLE;

	return int(result);
}