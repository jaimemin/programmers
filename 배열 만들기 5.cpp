#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> intStrs, int k, int s, int l) {
    vector<int> answer;

    for (string intStr : intStrs)
    {
        string sub = intStr.substr(s, l);

        if (stoi(sub) > k)
        {
            answer.push_back(stoi(sub));
        }
    }

    return answer;
}