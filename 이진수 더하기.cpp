#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string solution(string bin1, string bin2) {
    string answer = "";
    int carry = 0;
    reverse(bin1.begin(), bin1.end());
    reverse(bin2.begin(), bin2.end());
    
    for (int i = 0; i < min(bin1.length(), bin2.length()); i++)
    {
        int a = bin1[i] - '0';
        int b = bin2[i] - '0';
        
        if (a + b + carry >= 2)
        {
            answer += (a + b + carry - 2) + '0';
            
            carry = 1;
        }
        else
        {
            answer += (a + b + carry) + '0';
            
            carry = 0;
        }
    }
    
    for (int i = min(bin1.length(), bin2.length()); i < max(bin1.length(), bin2.length()); i++)
    {
        int sum = bin1.length() > bin2.length() ? bin1[i] - '0' + carry : bin2[i] - '0' + carry;
        
        if (sum >= 2)
        {
            answer += (sum - 2) + '0';
            
            carry = 1;
        }
        else
        {
            answer += sum + '0';
            
            carry = 0;
        }
    }
    
    if (carry)
    {
        answer += "1";
    }
    
    reverse(answer.begin(), answer.end());
    
    return answer;
}
