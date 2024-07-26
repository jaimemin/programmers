#include <cmath>
using namespace std;

int func(int n, int plusCnt)
{
    if (n < 1)
    {
        return 0;
    }
    
    if ((log(n) / log(3)) < (plusCnt + 1) / 2)
    {
        return 0;
    }
    
    if (n == 3 && plusCnt == 2)
    {
        return 1;
    }
    
    int result = 0;
    
    if (n % 3 == 0 && plusCnt >= 2)
    {
        result += func(n/3, plusCnt - 2);
	}
    
    result += func(n - 1, plusCnt + 1);
    
    return result;
}

int solution(int n) {
    return func(n - 2, 2);
}
