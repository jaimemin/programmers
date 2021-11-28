#include <string>
#include <vector>
#include <cmath>
using namespace std;

int solution(string dartResult) {
	string temp = "";
	vector<int> v;

	for (char c : dartResult)
	{
		if (c >= '0' && c <= '9')
		{
			temp += c;
		}
		else if (c == 'S' || c == 'D' || c == 'T')
		{
			int num = stoi(temp);
			num = pow(num, c == 'S' ? 1 : c == 'D' ? 2 : 3);
			v.push_back(num);

			temp = "";
		}
		else if (c == '*')
		{
			int rIdx = v.size() - 1;
			v[rIdx] *= 2;

			if (rIdx > 0)
			{
				v[rIdx - 1] *= 2;
			}
		}
		else if (c == '#')
		{
			int rIdx = v.size() - 1;
			v[rIdx] *= -1;
		}
	}

	int answer = 0;

	for (int num : v)
	{
		answer += num;
	}

	return answer;
}