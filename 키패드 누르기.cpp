#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

pair<int, int> left = { 3, 0 }, right = { 3, 2 };
map<int, pair<int, int>> number2coord;

char getFinger(int number, string hand)
{
	pair<int, int> coord = number2coord[number];
	int leftLength = abs(left.first - coord.first) + abs(left.second - coord.second);
	int rightLength = abs(right.first - coord.first) + abs(right.second - coord.second);

	if (leftLength < rightLength)
	{
		left = coord;

		return 'L';
	}
	else if (leftLength > rightLength)
	{
		right = coord;

		return 'R';
	}
	else
	{
		hand == "right" ? right = coord : left = coord;

		return toupper(hand[0]);
	}
}

void init(void)
{
	number2coord[0] = { 3, 1 };
	number2coord[1] = { 0, 0 };
	number2coord[2] = { 0, 1 };
	number2coord[3] = { 0, 2 };
	number2coord[4] = { 1, 0 };
	number2coord[5] = { 1, 1 };
	number2coord[6] = { 1, 2 };
	number2coord[7] = { 2, 0 };
	number2coord[8] = { 2, 1 };
	number2coord[9] = { 2, 2 };
}

string solution(vector<int> numbers, string hand) {
	init();
	string answer;

	for (int number : numbers)
	{
		switch (number)
		{
		case 1:
		case 4:
		case 7:
			answer += 'L';
			left = number2coord[number];

			break;
		case 3:
		case 6:
		case 9:
			answer += 'R';
			right = number2coord[number];

			break;
		default:
			answer += getFinger(number, hand);
		}
	}

	return answer;
}