#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string solution(string s) {
	vector<long long> v;
	string temp;

	for (char c : s)
	{
		if (c == ' ')
		{
			v.push_back(stoll(temp));
			temp = "";

			continue;
		}

		temp += c;
	}

	v.push_back(stoll(temp));

	sort(v.begin(), v.end());

	string answer = to_string(v[0]) + " " + to_string(v.back());

	return answer;
}