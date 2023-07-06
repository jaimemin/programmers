#include <string>
#include <vector>

using namespace std;

bool isSeperator(char c)
{
    return c == 'a' || c == 'b' || c == 'c';
}

vector<string> solution(string myStr) {
    vector<string> answer;
    string temp = "";
    
    for (char c : myStr)
    {
        if (isSeperator(c))
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
    
    if (answer.empty())
    {
        answer.push_back("EMPTY");
    }
    
    return answer;
}