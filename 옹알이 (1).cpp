#include <string>
#include <vector>
#include <set>
using namespace std;

set<string> pronounciations;

void init()
{
    pronounciations.insert("aya");
    pronounciations.insert("ye");
    pronounciations.insert("woo");
    pronounciations.insert("ma");
}

int solution(vector<string> babbling) {
    init();

    int answer = 0;

    for (string b : babbling)
    {
        set<string> visited;
        string temp = "";

        for (char c : b)
        {
            temp += c;

            if (pronounciations.find(temp) != pronounciations.end()
                && visited.find(temp) == visited.end())
            {
                visited.insert(temp);

                temp = "";
            }
        }

        if (temp == "")
        {
            answer++;
        }
    }

    return answer;
}