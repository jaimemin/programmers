#include <string>
#include <vector>

using namespace std;

int solution(string my_string) {
    int answer = 0;
    string temp = "";
    string str = "+";
    
    for (char c : my_string)
    {
        if(isdigit(c))
        {
            temp += c;
        }
        else if(c == '+')
        {    
            int num = stoi(temp);
            answer += (str == "+" ? num : -num);
            
            temp = "";
            str = "+";
        }
        else if(c == '-')
        {
            int num = stoi(temp);
            answer += (str == "+" ? num : -num);
            
            temp = "";
            str = "-";
        }
    }
    
    if (!temp.empty()) 
    { 
        int num = stoi(temp);
        
        answer += (str == "+" ? num : -num);
    }
    
    return answer;
}
