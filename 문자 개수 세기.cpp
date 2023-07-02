#include <string>
#include <vector>

using namespace std;

vector<int> solution(string my_string) {
    vector<int> answer(52, 0);

    for (char c : my_string)
    {
        answer[c >= 'a' ? c - 'a' + 26 : c - 'A']++;
    }

    return answer;
}