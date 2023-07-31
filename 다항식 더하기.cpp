#include <string>
#include <vector>
#include <iostream>
using namespace std;

int nums[2] = {0, 0};

string solution(string polynomial) {
    string answer = "";
    string temp = "";
    
    for (char c : polynomial)
    {
        if (c == '+')
        {
            continue;
        }
        
        if (c == ' ')
        {
            if (temp != "")
            {
                nums[1] += stoi(temp);
                temp = "";
            }
            
            continue;
        }
        
        if (c == 'x')
        {
            if (temp != "")
            {
                nums[0] += stoi(temp);
                
                temp = "";
            }
            else
            {
                nums[0]++;
            }
            
            continue;
        }
        
        temp += c;
    }
    
    if (temp != "")
    {
        nums[1] += stoi(temp);
    }
    
    if (nums[0] != 0)
    {
        answer += (nums[0] == 1 ? "" : to_string(nums[0])) + "x";
    }
    
    if (nums[0] != 0 && nums[1])
    {
        answer += " + ";
        answer += to_string(nums[1]);
    }
    
    if (nums[0] == 0 && nums[1])
    {
        answer += to_string(nums[1]);
    }
    
    if (nums[0] == 0 && nums[1] == 0)
    {
        answer += "0";
    }
    
    return answer;
}
