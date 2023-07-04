#include <string>
#include <vector>
using namespace std;

string makeUpper(string s)
{
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] >= 'a')
        {
            s[i] = s[i] - 'a' + 'A';
        }
    }
    
    return s;
}

string makeLower(string s)
{
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] < 'a')
        {
            s[i] = s[i] - 'A' + 'a';
        }
    }
    
    return s;
}

vector<string> solution(vector<string> strArr) {
    vector<string> answer;
    
    for (int i = 0; i < strArr.size(); i++)
    {
        answer.push_back(i % 2 ? makeUpper(strArr[i]) : makeLower(strArr[i]));
    }
    
    return answer;
}