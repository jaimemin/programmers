#include <string>
#include <vector>

using namespace std;

string solution(string my_string, string letter) {
    string answer = "";
    
    for (char c : my_string)
    {
        string s = "";
        s += c;
        
        if (s == letter)
        {
            continue;
        }
        
        answer += c;
    }
    
    return answer;
}
