#include <string>
#include <vector>
#include <set>
using namespace std;

set<string> words;

void init()
{
    words.insert("aya");
    words.insert("ye");
    words.insert("woo");
    words.insert("ma");
}

int solution(vector<string> babbling) {
    init();

    int answer = 0;

    for (string b : babbling)
    {
        string prev, cur;

        for (char c : b)
        {
            cur += c;

            if (prev != cur && words.find(cur) != words.end())
            {
                prev = cur;

                cur = "";
            }
        }

        if (cur == "")
        {
            answer++;
        }
    }

    return answer;
}