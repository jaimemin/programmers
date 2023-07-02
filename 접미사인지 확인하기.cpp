#include <string>
#include <vector>
#include <set>
using namespace std;

int solution(string my_string, string is_suffix) {
    set<string> suffixes;

    for (int i = 0; i < my_string.length(); i++)
    {
        suffixes.insert(my_string.substr(i));
    }

    return suffixes.find(is_suffix) != suffixes.end();
}