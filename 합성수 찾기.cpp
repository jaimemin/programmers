#include <string>
#include <vector>
#include <iostream>
using namespace std;

bool func(int n)
{
    for (int i = 2; i < n; i++)
    {
        if (n % i == 0)
        {
            return true;
        }
    }
    
    return false;    
}

int solution(int n) {
    int answer = 0;
    
    for (int i = 3; i <= n; i++)
    {
        answer += func(i);
    }
    
    return answer;
}
