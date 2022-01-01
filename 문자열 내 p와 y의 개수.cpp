#include <string>
#include <iostream>
using namespace std;

bool solution(string s)
{
	int yCnt = 0, pCnt = 0;

	for (char c : s)
	{
		if (c == 'y' || c == 'Y')
		{
			yCnt++;
		}
		else if (c == 'p' || c == 'P')
		{
			pCnt++;
		}
	}

	return yCnt == pCnt;
}