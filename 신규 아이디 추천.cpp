#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool isFitForSecondRound(char c)
{
	return (c >= 'a' && c <= 'z')
		|| (c >= '0' && c <= '9')
		|| c == '-'
		|| c == '_'
		|| c == '.';
}

string solution(string new_id) {
	string answer = new_id;

	// 1단계
	for (int i = 0; i < answer.length(); i++)
	{
		if (answer[i] >= 'A' && answer[i] <= 'Z')
		{
			answer[i] += 'a' - 'A';
		}
	}

	// 2단계
	string temp;

	for (int i = 0; i < answer.length(); i++)
	{
		if (isFitForSecondRound(answer[i]))
		{
			temp += answer[i];
		}
	}

	answer = temp;
	temp = "";

	// 3단계
	for (int i = 0; i < answer.length(); i++)
	{
		if (i != answer.length() - 1
			&& answer[i] == '.' && answer[i + 1] == '.')
		{
			temp += '.';

			while (i != answer.length() - 1 && answer[i + 1] == '.')
			{
				i++;
			}

			continue;
		}

		temp += answer[i];
	}

	answer = temp;
	temp = "";

	// 4단계
	while (!answer.empty() && answer[0] == '.')
	{
		answer = answer.substr(1);
	}

	while (!answer.empty() && answer[answer.length() - 1] == '.')
	{
		answer = answer.substr(0, answer.length() - 1);
	}

	// 5단계
	if (answer.empty())
	{
		answer = "a";
	}

	// 6단계
	if (answer.length() >= 16)
	{
		answer = answer.substr(0, 15);

		if (answer[answer.length() - 1] == '.')
		{
			answer = answer.substr(0, answer.length() - 1);
		}
	}

	// 7단계
	if (answer.length() <= 2)
	{
		char c = answer[answer.length() - 1];

		while (answer.length() < 3)
		{
			answer += c;
		}
	}

	return answer;
}