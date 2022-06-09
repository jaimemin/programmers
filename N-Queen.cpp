#include <string>
#include <vector>
using namespace std;

const int MAX = 12;

int col[MAX + 1];

int answer;

bool promising(int idx)
{
	int k = 1;
	bool flag = true;

	while (k < idx && flag)
	{
		if (col[idx] == col[k]
			|| abs(col[idx] - col[k]) == idx - k)
		{
			flag = false;
		}

		k++;
	}

	return flag;
}

void queens(int idx, int n)
{
	if (promising(idx))
	{
		if (idx == n)
		{
			answer++;
		}
		else
		{
			for (int i = 1; i <= n; i++)
			{
				col[idx + 1] = i;

				queens(idx + 1, n);
			}
		}
	}
}

int solution(int n) {
	queens(0, n);

	return answer;
}