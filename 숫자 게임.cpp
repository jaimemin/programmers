#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> A, vector<int> B) {
	sort(A.begin(), A.end());
	sort(B.begin(), B.end());

	int answer = 0;
	int aIdx = A.size() - 1, bIdx = B.size() - 1;

	for (int i = 0; i < A.size(); i++)
	{
		int maxA = A[aIdx];
		int maxB = B[bIdx];

		if (maxB > maxA)
		{
			answer++;

			bIdx--;
		}
		
		aIdx--;
	}

	return answer;
}