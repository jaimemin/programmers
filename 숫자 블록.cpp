#include <string>
#include <vector>
using namespace std;

int func(int num)
{
	if (num == 1)
	{
		return 0;
	}

	for (int i = 2; i * i <= num; i++)
	{
		if (num % i == 0 && num / i <= 1e7)
		{
			return num / i;
		}
	}

	return 1;
}

vector<int> solution(long long begin, long long end) {
	vector<int> answer;

	for (long long i = begin; i <= end; i++)
	{
		answer.push_back(func(i));
	}

	return answer;
}