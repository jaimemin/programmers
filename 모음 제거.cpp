#include <string>
#include <vector>

using namespace std;

string solution(string my_string) {
    string answer = "";
    
    for (char c : my_string)
    {
        if (c == 'a' 
            || c == 'e' 
            || c == 'i' 
            || c == 'o' 
            || c == 'u')
        {
            continue;
        }
        
        answer += c;
    }
    
    return answer;
}
