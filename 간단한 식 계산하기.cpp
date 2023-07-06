#include <string>
#include <vector>

using namespace std;

bool isOp(char c)
{
    return c == '+' || c == '-' || c == '*';
}

int solution(string binomial) {
    int answer = 0;
    int first = 0;
    char op = '+';
    string temp = "";
    
    for (char c : binomial)
    {
        if (c == ' ')
        {
            if (temp != "")
            {
                first = stoi(temp);
                temp = "";
            }
            
            continue;
        }
        
        if (isOp(c))
        {
            op = c;
            
            continue;
        }
        
        temp += c;
    }
    
    switch (op)
    {
        case '+':
            answer = first + stoi(temp);
            
            break;
        case '-':
            answer = first - stoi(temp);
            
            break;
        case '*':
            answer = first * stoi(temp);
            
            break;
    }
    
    return answer;
}