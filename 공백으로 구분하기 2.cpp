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
            if (temp == "")
            {
                continue;
            }
            
            answer.push_back(temp);
            temp = "";
            
            continue;
        }
        
        temp += c;
    }
    
    if (temp != "")
    {
        answer.push_back(temp);
    }
    
    return answer;
}