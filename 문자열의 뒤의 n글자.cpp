#include <string>
#include <vector>

using namespace std;

string solution(string my_string, int n) {
    int length = my_string.length();
    
    return my_string.substr(length - n);
}