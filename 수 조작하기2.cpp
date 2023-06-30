#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string solution(vector<int> numLog) {
    string answer = "";

    for (int i = numLog.size() - 1; i > 0; i--)
    {
        int cur = numLog[i];
        int prev = numLog[i - 1];

        if (cur - prev == 1)
        {
            answer += "w";
        }
        else if (cur - prev == -1)
        {
            answer += "s";
        }
        else if (cur - prev == 10)
        {
            answer += "d";
        }
        else
        {
            answer += "a";
        }
    }

    reverse(answer.begin(), answer.end());

    return answer;
}