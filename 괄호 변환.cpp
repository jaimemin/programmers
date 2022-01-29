#include <string>
#include <vector>
#include <stack>
#include <iostream>
using namespace std;

typedef struct
{
	string u, v;
} W;

string result;

W getW(string w)
{
	// 1
	if (w == "")
	{
		return { "", "" };
	}

	// 2
	string u = "", v = "";
	int openCnt = 0, closeCnt = 0;
	int vIdx = w.length();

	for (int i = 0; i < w.length(); i++)
	{
		if (w[i] == '(')
		{
			u += w[i];

			if (++openCnt == closeCnt)
			{
				vIdx = i + 1;

				break;
			}
		}
		else
		{
			u += w[i];

			if (++closeCnt == openCnt)
			{
				vIdx = i + 1;

				break;
			}
		}
	}

	v = w.substr(vIdx);

	return { u, v };
}

string getResult(string p)
{
	if (p == "")
	{
		return p;
	}

	W w = getW(p);
	string u = w.u;
	string v = w.v;

	stack<char> st;
	bool isCorrect = true;

	for (char c : u)
	{
		if (c == '(')
		{
			st.push(c);
		}
		else
		{
			if (st.empty())
			{
				isCorrect = false;

				break;
			}

			st.pop();
		}
	}

	if (!st.empty())
	{
		isCorrect = false;
	}

	// 3
	if (isCorrect)
	{
		return u + getResult(v);
	}

	// 4
	string temp = "(";
	temp += getResult(v);
	temp += ")";

	for (int i = 1; i < u.length() - 1; i++)
	{
		temp += u[i] == '(' ? ')' : '(';
	}

	return temp;
}

string solution(string p) {
	return getResult(p);
}

int main(void)
{
	string p = "()))((()";

	cout << solution(p) << "\n";

	return 0;
}