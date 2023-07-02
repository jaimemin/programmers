#include <string>
#include <vector>
#include <set>
using namespace std;

int solution(string my_string, string is_prefix) {
    set<string> prefixes;

    for (int i = 0; i < my_string.length(); i++)
    {
        prefixes.insert(my_string.substr(0, i));
    }

    return prefixes.find(is_prefix) != prefixes.end();
}