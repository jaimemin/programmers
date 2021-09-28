#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> sizes) {
	int width = 0;
	int height = 0;

	for (auto size : sizes)
	{
		width = max(width, max(size[0], size[1]));
		height = max(height, min(size[0], size[1]));
	}

	return width * height;
}

int main(void)
{
	vector<vector<int>> sizes = {
		{60, 50},
		{30, 70},
		{60, 30},
		{80, 40}
	};

	cout << solution(sizes) << "\n";

	return 0;
}