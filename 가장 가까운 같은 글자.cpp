#include <string>
#include <vector>
#include <map>
using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    map<char, int> char2pos;

    for (int i = 0; i < s.length(); i++)
    {
        if (!char2pos.count(s[i]))
        {
            answer.push_back(-1);

            char2pos[s[i]] = i;
        }
        else
        {
            answer.push_back(i - char2pos[s[i]]);

            char2pos[s[i]] = i;
        }
    }

    return answer;
}