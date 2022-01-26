#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

const int MAX = 8;

const char names[MAX] = { 'A', 'C', 'F', 'J', 'M', 'N', 'R', 'T' };

int result;

bool isPossible(string friends, vector<string> &data)
{
	for (string d : data)
	{
		int from = friends.find(d[0]);
		int target = friends.find(d[2]);
		char op = d[3];
		int distance = (d[4] - '0') + 1;
		int realDistance = abs(from - target);

		switch (op)
		{
		case '=':
			if (!(realDistance == distance))
			{
				return false;
			}

			break;
		case '>':
			if (!(realDistance > distance))
			{
				return false;
			}

			break;
		case '<':
			if (!(realDistance < distance))
			{
				return false;
			}

			break;
		}
	}

	return true;
}

void func(string friends, bool visited[MAX], vector<string> &data)
{
	if (friends.length() == MAX - 1)
	{
		result += isPossible(friends, data);

		return;
	}

	for (int i = 0; i < MAX; i++)
	{
		if (visited[i])
		{
			continue;
		}

		visited[i] = true;
		func(friends + names[i], visited, data);
		visited[i] = false;
	}
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int n, vector<string> data) {
	result = 0;
	bool visited[MAX] = { false, };

	func("", visited, data);

	return result;
}