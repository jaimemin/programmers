#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;
    char start = ' ';
    int cnt = 1;
    int otherCnt = 0;

    for (char c : s)
    {
        if (start == ' ')
        {
            start = c;
            cnt = 1;
            otherCnt = 0;
            answer++;

            continue;
        }

        if (c != start)
        {
            if (++otherCnt == cnt)
            {
                start = ' ';
            }
        }
        else
        {
            cnt++;
        }
    }

    return answer;
}