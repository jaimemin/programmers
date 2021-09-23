#include <iostream>
#include <string>
#include <vector>
#include <set>
using namespace std;

vector<int> solution(vector<string> operations) {
	set<int> pq;
	
	for (string operation : operations)
	{
		char op = operation[0];

		if (op == 'I')
		{
			char sign = operation[2];

			if (sign == '-')
			{
				pq.insert(stoi(operation.substr(3)) * -1);
			}
			else
			{
				pq.insert(stoi(operation.substr(2)));
			}
		}
		else
		{
			if (pq.empty())
			{
				continue;
			}

			char sign = operation[2];

			if (sign == '-')
			{
				auto it = pq.begin();

				if (it != pq.end())
				{
					pq.erase(it);
				}
			}
			else
			{
				auto it = pq.end();

				if (it != pq.begin())
				{
					pq.erase(--it);
				}
			}
		}
	}

	if (pq.empty())
	{
		return { 0, 0 };
	}
	else
	{
		return { *pq.rbegin(), *pq.begin() };
	}
}

int main(void)
{
	vector<string> operations = {
		{"I 7"},
		{"I 5"},
		{"I -5"},
		{"D -1"}
	};

	vector<int> answers = solution(operations);

	for (int answer : answers)
	{
		cout << answer << " ";
	}

	cout << "\n";

	return 0;
}