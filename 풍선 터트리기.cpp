#include <string>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 1000000 + 1000;

int cache[MAX][2]; // [a¿« ≈©±‚[isLeft?]

int solution(vector<int> a) {
	int answer = 2;

	int left = a.front();
	int right = a.back();

	for (int i = 1; i < a.size(); i++) {
		left = min(left, a[i]);

		cache[i][0] = left;
	}

	for (int i = a.size() - 2; i > 0; i--)
	{
		right = min(right, a[i]);

		cache[i][1] = right;
	}

	for (int i = 1; i < a.size() - 1; i++) 
	{
		if (a[i] <= cache[i][0] || a[i] <= cache[i][1])
		{
			answer++;
		}
	}

	return answer;
}