#include <string>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 987654321;

int solution(string A, string B) {
    if (A == B)
    {
        return 0;
    }

    int len = A.length();
    string s = A;
    int answer = INF;

    for (int i = 0; i < len; i++)
    {
        s = s[len - 1] + s.substr(0, len - 1);

        if (s == B)
        {
            return i + 1;
        }
    }

    return -1;
}