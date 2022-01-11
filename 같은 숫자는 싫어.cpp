#include <vector>
#include <iostream>
using namespace std;

vector<int> solution(vector<int> arr)
{
	vector<int> answer;

	if (arr.empty())
	{
		return answer;
	}

	int temp = arr[0];
	answer.push_back(temp);

	for (int i = 1; i < arr.size(); i++)
	{
		if (temp == arr[i])
		{
			continue;
		}

		answer.push_back(arr[i]);
		temp = arr[i];
	}

	return answer;
}