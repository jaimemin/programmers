#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int GCD(int a, int b)
{
	if (a % b == 0)
	{
		return b;
	}

	return GCD(b, a % b);
}

int LCM(int a, int b)
{
	return a * b / GCD(a, b);
}

int solution(vector<int> arr) {
	sort(arr.begin(), arr.end());

	int answer = arr.back();

	for (int i = arr.size() - 2; i >= 0; i--)
	{
		answer = LCM(answer, arr[i]);
	}

	return answer;
}