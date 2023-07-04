#include <string>
#include <vector>

using namespace std;

vector<string> solution(vector<string> str_list) {
    vector<string> answer;
    bool flag = false;
    
    for (string s : str_list)
    {
        if (flag == false && s == "r")
        {
            flag = true;
            answer.clear();
            
            continue;
        }
        
        if (flag == false && s == "l")
        {
            flag = true;
            
            break;
        }
        
        answer.push_back(s);
    }
    
    if (!flag)
    {
        answer.clear();   
    }
    
    return answer;
}