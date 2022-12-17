#include <string>
#include <vector>

using namespace std;

vector<string> solution(string my_str, int n) {
    vector<string> answer;
    int idx = 0;

    while (idx < my_str.length())
    {
        answer.push_back(my_str.substr(idx, n));

        idx += n;
    }


    return answer;
}