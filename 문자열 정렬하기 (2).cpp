#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string solution(string my_string) {
    string answer = "";

    for (char c : my_string)
    {
        answer += c <= 'Z' ? c - 'A' + 'a' : c;
    }

    sort(answer.begin(), answer.end());

    return answer;
}