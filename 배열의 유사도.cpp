#include <string>
#include <vector>
#include <set>
using namespace std;

int solution(vector<string> s1, vector<string> s2) {
    int answer = 0;
    set<string> visited;

    for (string s : s1)
    {
        visited.insert(s);
    }

    for (string s : s2) {
        if (visited.find(s) != visited.end())
        {
            answer++;
        }
    }

    return answer;
}