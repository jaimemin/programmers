#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string solution(string number, int k) {
	string answer = number.substr(k);

	for (int i = k - 1; i >= 0; i--)
	{
		int idx = 0;

		while (idx < answer.size())
		{
			if (answer[idx] > number[i])
			{
				break;
			}

			swap(answer[idx++], number[i]);
		}
	}

	return answer;
}

int main(void)
{
	string number = "1231234";
	int k = 3;

	cout << solution(number, k) << "\n";

	return 0;
}