#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> routes) {
	sort(routes.begin(), routes.end());

	int cameraPlacement = routes[0][1];
	int answer = 1;

	for (int i = 1; i < routes.size(); i++)
	{
		if (cameraPlacement >= routes[i][0])
		{
			cameraPlacement = min(cameraPlacement, routes[i][1]);
		}
		else
		{
			cameraPlacement = routes[i][1];
			answer++;
		}
	}

	return answer;
}

int main(void)
{
	vector<vector<int>> routes = { {-20, 15}, {-14, -5}, {-18, -13}, {-5, -3} };

	cout << solution(routes) << "\n";

	return 0;
}