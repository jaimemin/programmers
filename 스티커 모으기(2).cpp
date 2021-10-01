#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> sticker)
{
	if (sticker.size() == 1)
	{
		return sticker.front();
	}

	vector<int> cache, cache2;

	for (int i = 0; i < 2; i++)
	{
		cache.push_back(sticker[0]);
	}

	for (int i = 2; i < sticker.size() - 1; i++)
	{
		cache.push_back(max(cache[i - 1], cache[i - 2] + sticker[i]));
	}

	cache2.push_back(0);
	cache2.push_back(sticker[1]);

	for (int i = 2; i < sticker.size(); i++)
	{
		cache2.push_back(max(cache2[i - 1], cache2[i - 2] + sticker[i]));
	}

	return max(cache.back(), cache2.back());
}

int main(void)
{
	vector<int> sticker = { 14, 6, 5, 11, 3, 9, 2, 10 };

	cout << solution(sticker) << "\n";

	return 0;
}