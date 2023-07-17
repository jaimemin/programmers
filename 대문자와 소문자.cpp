#include <string>
#include <vector>

using namespace std;

string solution(string my_string) {
    string answer = "";

    for (char c : my_string)
    {
        answer += c >= 'a' ? c - 'a' + 'A' : c - 'A' + 'a';
    }

    return answer;
}