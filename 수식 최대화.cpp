#include <string>
#include <vector>
#include <stack>
#include <algorithm>
#include <map>
#include <climits>
#include <iostream>
using namespace std;

map<int, string> idx2op;

void init(void)
{
	idx2op[0] = "+";
	idx2op[1] = "-";
	idx2op[2] = "*";
}

bool isNumber(char c)
{
	return c >= '0' && c <= '9';
}

long long solution(string expression) {
	long long answer = LLONG_MIN;
	vector<int> v;

	for (int i = 0; i < 3; i++)
	{
		v.push_back(i);
	}

	init();

	do
	{
		map<string, int> op2priority;

		// 연산자 우선순위 부여
		for (int i = 0; i < 3; i++)
		{
			op2priority[idx2op[i]] = v[i];
		}

		stack<string> st;
		vector<string> postfix;
		string temp;

		for (int i = 0; i < expression.length(); i++)
		{
			char c = expression[i];

			if (isNumber(c))
			{
				temp += c;
			}
			else
			{
				if (!temp.empty())
				{
					postfix.push_back(temp);
					temp.clear();
				}

				string opTemp = "";
				opTemp += c;

				int priority = op2priority[opTemp];

				switch (priority)
				{
				case 2:
					while (!st.empty()
						&& op2priority.count(st.top())
						&& op2priority[st.top()] == priority)
					{
						postfix.push_back(st.top());
						st.pop();
					}

					st.push(opTemp);

					break;
				case 1:
					while (!st.empty()
						&& op2priority.count(st.top())
						&& op2priority[st.top()] >= priority)
					{
						postfix.push_back(st.top());
						st.pop();
					}

					st.push(opTemp);

					break;
				case 0:
					while (!st.empty())
					{
						postfix.push_back(st.top());
						st.pop();
					}

					st.push(opTemp);

					break;
				}
			}
		}

		if (!temp.empty())
		{
			postfix.push_back(temp);
		}

		while (!st.empty())
		{
			postfix.push_back(st.top());
			st.pop();
		}

		long long result = 0;

		for (int i = 0; i < postfix.size(); i++)
		{
			string s = postfix[i];

			if (s == "+" || s == "-" || s == "*")
			{
				long long num = stoll(st.top());
				st.pop();
				long long num2 = stoll(st.top());
				st.pop();
				long long temp = 0;

				if (s == "+")
				{
					temp = num + num2;
				}
				else if (s == "-")
				{
					temp = num2 - num;
				}
				else
				{
					temp = num * num2;
				}

				st.push(to_string(temp));
			}
			else
			{
				st.push(s);
			}
		}

		answer = max(answer, abs(stoll(st.top())));
	} while (next_permutation(v.begin(), v.end()));

	return answer;
}

int main(void)
{
	string expression = "100-200*300-500+20";

	cout << solution(expression) << "\n";

	return 0;
}