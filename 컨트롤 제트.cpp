#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(string s) {
    int answer = 0;
    int prev = 0;
    string temp = "";
    
    for (char c : s)
    {
        if (c == ' ')
        {
            if (temp != "")
            {
                prev = stoi(temp);
                answer += prev;
                temp = "";
            }
            
            continue;
        }
        
        if (c == 'Z')
        {
            answer -= prev;
            
            continue;
        }
        
        temp += c;
    }
    
    if (temp != "")
    {
        answer += stoi(temp);
    }
    
    return answer;
}
