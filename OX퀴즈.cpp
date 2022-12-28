#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<string> solution(vector<string> quiz) {
    vector<string> answer;

    for (string q : quiz)
    {
        string num1, num2;
        char op;
        int opIdx, equalIdx;

        for (int i = 1; i < q.length(); i++)
        {
            if (q[i] == '-' || q[i] == '+')
            {
                num1 = q.substr(0, i);
                opIdx = i;
                op = q[i];

                break;
            }
        }

        for (int i = opIdx + 1; i < q.length(); i++)
        {
            if (q[i] == '=')
            {
                equalIdx = i;

                break;
            }
        }

        num2 = q.substr(opIdx + 1, equalIdx - opIdx - 1);
        int result = stoi(q.substr(equalIdx + 1));


        if (op == '+')
        {
            answer.push_back(stoi(num1) + stoi(num2) == result ? "O" : "X");
        }
        else
        {
            answer.push_back(stoi(num1) - stoi(num2) == result ? "O" : "X");
        }
    }

    return answer;
}

int main(void)
{
    vector<string> quiz = { "3 - 4 = -3", "5 + 6 = 11" };

    vector<string> v = solution(quiz);

    return 0;
}