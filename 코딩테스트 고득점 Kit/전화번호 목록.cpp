#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
using namespace std;

bool solution(vector<string> phone_book) {
	bool answer = true;

	int idx = 0;
	set<string> visited;
	map<string, int> number2idx;

	for (string number : phone_book)
	{
		visited.insert(number);
		number2idx[number] = idx++;
	}

	for (int i = 0; i < phone_book.size(); i++)
	{
		string number = phone_book[i];

		for (int j = 1; j <= number.length(); j++)
		{
			string temp = number.substr(0, j);

			if (visited.count(temp) && number2idx[temp] != i)
			{
				answer = false;

				break;
			}
		}

		if (answer == false)
		{
			break;
		}
	}

	return answer;
}

int main(void)
{
	vector<string> phone_book = { "119", "97674223", "1195524421" };

	cout << solution(phone_book) << "\n";

	return 0;
}