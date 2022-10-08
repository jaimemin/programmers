#include <string>
#include <vector>

using namespace std;

vector<int> getPartialMatch(const string& s)
{
    int len = s.length();
    vector<int> pi(len, 0);

    int begin = 1, matched = 0;

    while (begin + matched < len)
    {
        if (s[begin + matched] == s[matched])
        {
            matched++;

            pi[begin + matched - 1] = matched;
        }
        else
        {
            if (matched == 0)
            {
                begin++;
            }
            else
            {
                begin += matched - pi[matched - 1];
                matched = pi[matched - 1];
            }
        }
    }

    return pi;
}

int kmp(const string& s, const string& target)
{
    vector<int> result;
    vector<int> pi = getPartialMatch(target);
    int matched = 0;

    for (int i = 0; i < s.length(); i++)
    {
        while (matched > 0 && s[i] != target[matched])
        {
            matched = pi[matched - 1];
        }

        if (s[i] == target[matched])
        {
            matched++;

            if (matched == target.length())
            {
                result.push_back(i - target.length() + 1);
                matched = 0;
            }
        }
    }

    return result.size();
}

int solution(string str1, string str2) {
    return kmp(str1, str2) > 0 ? 1 : 2;
}