#include <string>
#include <vector>

using namespace std;

double solution(vector<int> arr) {
	double answer = 0;

	for (int num : arr)
	{
		answer += num;
	}

	answer /= arr.size();

	return answer;
}