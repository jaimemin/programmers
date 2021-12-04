#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> convertToBinary(int n, int num)
{
	vector<int> v;

	while (num)
	{
		v.push_back(num % 2);

		num /= 2;
	}

	while (v.size() < n)
	{
		v.push_back(0);
	}

	reverse(v.begin(), v.end());

	return v;
}

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
	vector<string> answer;

	for (int i = 0; i < n; i++)
	{
		vector<int> v = convertToBinary(n, arr1[i]);
		vector<int> v2 = convertToBinary(n, arr2[i]);
		string temp;

		for (int j = 0; j < v.size(); j++)
		{
			temp.push_back(v[j] || v2[j] ? '#' : ' ');
		}

		answer.push_back(temp);
	}

	return answer;
}