#include <iostream>
#include <string>
#include <vector>
using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
	vector<int> students(n + 1, 1);
	students[0] = 0;

	for (int idx : lost)
	{
		students[idx]--;
	}

	for (int idx : reserve)
	{
		students[idx]++;
	}

	for (int i = 1; i <= n; i++)
	{
		if (students[i])
		{
			continue;
		}

		if (i != 1 && students[i - 1] == 2)
		{
			students[i]++;
			students[i - 1]--;
		} 
		else if (i != n && students[i + 1] == 2)
		{
			students[i]++;
			students[i + 1]--;
		}
	}

	int answer = 0;

	for (int student : students)
	{
		answer += (student >= 1 ? 1 : 0);
	}

	return answer;
}

int main(void)
{
	int n = 5;
	vector<int> lost = { 2, 4 };
	vector<int> reserve = { 1, 3, 5 };

	cout << solution(n, lost, reserve) << "\n";

	return 0;
}