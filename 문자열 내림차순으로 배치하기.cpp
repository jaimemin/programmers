#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(char a, char b)
{
	return a > b;
}

string solution(string s) {
	sort(s.begin(), s.end(), cmp);

	return s;
}