#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;

bool isCorrect(string s)
{
	stack<char> st;

	for (char c : s)
	{
		if (!st.empty())
		{
			bool matched = false;

			switch (st.top())
			{
			case '[':
				if (c == ']')
				{
					matched = true;

					st.pop();
				}

				break;
			case '{':
				if (c == '}')
				{
					matched = true;

					st.pop();
				}

				break;
			case '(':
				if (c == ')')
				{
					matched = true;

					st.pop();
				}

				break;
			}

			if (matched)
			{
				continue;
			}
		}

		st.push(c);
	}

	return st.empty();
}

int solution(string s) {
	int answer = 0;

	for (int i = 0; i < s.length(); i++)
	{
		if (isCorrect(s))
		{
			answer++;
		}

		char c = s.front();
		s = s.substr(1);
		s += c;
	}

	return answer;
}