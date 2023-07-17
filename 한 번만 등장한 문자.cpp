#include <string>
#include <vector>
#include <set>
#include <map>
using namespace std;

string solution(string s) {
    set<char> st;
    map<char, int> char2cnt;

    for (char c : s)
    {
        st.insert(c);
        char2cnt[c]++;
    }

    string answer = "";

    for (char c : st)
    {
        if (char2cnt[c] == 1)
        {
            answer += c;
        }
    }

    return answer;
}