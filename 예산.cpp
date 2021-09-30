#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> d, int budget) {
	int answer = 0;

	sort(d.begin(), d.end());

	for (int money : d)
	{
		if (budget - money >= 0)
		{
			budget -= money;
			answer++;
		}
	}

	return answer;
}