#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

bool onlyZero(string s)
{
    for (char c : s)
    {
        if (c != '0')
        {
            return false;
        }
    }

    return true;
}

string solution(string X, string Y) {
    map<char, int> visited;

    for (char c : X)
    {
        visited[c]++;
    }

    string s;

    for (char c : Y)
    {
        if (visited[c] != 0)
        {
            s += c;

            visited[c]--;
        }
    }

    if (s == "")
    {
        return "-1";
    }

    if (onlyZero(s))
    {
        return "0";
    }

    sort(s.begin(), s.end(), greater<char>());

    return s;
}