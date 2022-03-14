#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

const int MAX = 11;

int maxDiff;
vector<int> answer;

bool hasMoreLowerScore(vector<int> &v, vector<int> &answer)
{
	for (int i = MAX - 1; i >= 0; i--)
	{
		if (v[i] == answer[i])
		{
			continue;
		}

		if (v[i] > answer[i])
		{
			return true;
		}
		
		break;
	}

	return false;
}

int getDiff(vector<int> &v, vector<int> &info)
{
	int vScore = 0;
	int infoScore = 0;

	for (int i = 0; i < v.size(); i++)
	{
		int score = MAX - (i + 1);
		
		if (v[i] > info[i])
		{
			vScore += score;
		}
		else if (info[i])
		{
			infoScore += score;
		}
	}

	return vScore - infoScore;
}

void eval(vector<int> &v, vector<int> &info)
{
	int diff = getDiff(v, info);

	if (diff < 0)
	{
		return;
	}

	if (diff > maxDiff)
	{
		maxDiff = diff;
		answer = v;
	}

	if (diff == maxDiff && hasMoreLowerScore(v, answer))
	{
		maxDiff = diff;
		answer = v;
	}
}

void func(int idx, int total, vector<int> v, vector<int> &info)
{
	if (total == 0)
	{
		eval(v, info);

		return;
	}

	if (idx == MAX)
	{
		v.back() = total;
		eval(v, info);

		return;
	}

	int cnt = info[idx] + 1;

	if (total >= cnt)
	{
		v[idx] = cnt;
		func(idx + 1, total - cnt, v, info);
		v[idx] = 0;
	}

	func(idx + 1, total, v, info);
}

vector<int> solution(int n, vector<int> info) {
	if (n == 1)
	{
		return { -1 };
	}

	answer.resize(MAX, 0);
	vector<int> v(MAX, 0);
	func(0, n, v, info);

	if (!maxDiff)
	{
		return { -1 };
	}

	return answer;
}

int main(void)
{
	int n = 5;
	vector<int> info = { 2, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0 };

	vector<int> answer = solution(n, info);

	for (int a : answer)
	{
		cout << a << " ";
	}
	cout << "\n";

	return 0;
}