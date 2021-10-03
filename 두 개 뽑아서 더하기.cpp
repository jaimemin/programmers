#include <string>
#include <vector>
#include <set>
using namespace std;

vector<int> solution(vector<int> numbers) {
	set<int> numberSet;

	for (int i = 0; i < numbers.size(); i++)
	{
		for (int j = i + 1; j < numbers.size(); j++)
		{
			numberSet.insert(numbers[i] + numbers[j]);
		}
	}

	vector<int> answer;

	for (auto num : numberSet)
	{
		answer.push_back(num);
	}

	return answer;
}