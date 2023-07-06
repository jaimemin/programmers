#include <string>
#include <vector>

using namespace std;

vector<string> solution(string my_string) {
    vector<string> answer;
    string temp = "";
    
    for (char c : my_string)
    {
        if (c == ' ')
        {
            answer.push_back(temp);
            temp = "";
            
            continue;
        }
        
        temp += c;
    }
    
    answer.push_back(temp);
    
    return answer;
}