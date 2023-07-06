#include <string>
#include <vector>

using namespace std;

string solution(string n_str) {
    string answer = "";
    bool start = false;
    
    for (char c : n_str)
    {
        if (c != '0')
        {
            start = true;
        }
        
        if (start)
        {
            answer += c;
        }
    }
    
    return answer;
}