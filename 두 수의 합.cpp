#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

string solution(string a, string b) {
    int aIdx = a.length() - 1, bIdx = b.length() - 1;
    int carry = 0;
    string answer = "";
    
    while (aIdx != -1 && bIdx != -1)
    {
        int sum = (a[aIdx--] - '0') + (b[bIdx--] - '0') + carry;
        carry = 0;
        
        if (sum >= 10)
        {
            carry = 1;
            sum -= 10;
        }
        
        answer += (sum + '0');
    }
    
    for (int i = aIdx; i >= 0; i--)
    {
        int sum = (a[i] - '0') + carry;
        carry = 0;
        
        if (sum >= 10)
        {
            sum -= 10;
            carry = 1;
        }
        
        answer += (sum + '0');
    }
    
    for (int i = bIdx; i >= 0; i--)
    {
        int sum = (b[i] - '0') + carry;
        carry = 0;
        
        if (sum >= 10)
        {
            sum -= 10;
            carry = 1;
        }
        
        answer += (sum + '0');
    }
    
    if (carry)
    {
        answer += (carry + '0');
    }
    
    reverse(answer.begin(), answer.end());
    
    return answer;
}