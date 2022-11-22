#include <string>
#include <vector>
using namespace std;

const string HAMBURGER = "1231";

int solution(vector<int> ingredient) {
    int answer = 0;
    string s = "";

    for (int i : ingredient)
    {
        s += (i + '0');

        if (s.length() < 4)
        {
            continue;
        }

        if (s.substr(s.length() - 4) == HAMBURGER)
        {
            s = s.substr(0, s.length() - 4);

            answer++;
        }
    }

    return answer;
}