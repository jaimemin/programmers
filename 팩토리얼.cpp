#include <string>
#include <vector>

using namespace std;

long long getFactorial(int n)
{
    int result = 1;
    
    for (int i = 1; i <= n; i++)
    {
        result *= i;
    }
    
    return result;
}

int solution(int n) {
    for (int i = 1; ; i++)
    {
        long long result = getFactorial(i);
        
        if (result == n)
        {
            return i;
        }
        
        if (result > n)
        {
            return i - 1;
        }
    }
}
