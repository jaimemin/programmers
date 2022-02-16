#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> arr) {
	if (arr.size() == 1)
	{
		return { -1 };
	}

	vector<int> copyArr = arr;

	sort(copyArr.begin(), copyArr.end());

	vector<int> answer;

	for (int a : arr)
	{
		if (a == copyArr[0])
		{
			continue;
		}

		answer.push_back(a);
	}

	return answer;
}