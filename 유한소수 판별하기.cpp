#include <string>
#include <vector>

using namespace std;

int GCD(int a, int b)
{
    if (a % b == 0)
    {
        return b;
    }
 
    return GCD(b, a%b);
}

int solution(int a, int b) {
    b /= GCD(b, a);
    
    while (b % 2 == 0)
    {
        b /= 2;
    }
    
    while (b % 5 == 0)
    {
        b /= 5;
    }
    
    return b == 1 ? 1 : 2;
}
