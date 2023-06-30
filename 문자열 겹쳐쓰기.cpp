#include <string>
#include <vector>

using namespace std;

string solution(string my_string, string overwrite_string, int s) {
    int len = overwrite_string.length();
    string answer = my_string.substr(0, s) + overwrite_string.substr(0, len) + my_string.substr(s + len);

    return answer;
}