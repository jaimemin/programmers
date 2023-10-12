#include <string>
#include <vector>

using namespace std;

int GCD(int a, int b)
{
    if (a % b == 0)
    {
        return b;
    }
    
    return GCD(b, a % b);
}

int LCM(int a, int b)
{
    return (a * b) / GCD(a, b);
}

vector<int> solution(int numer1, int denom1, int numer2, int denom2) {
    vector<int> answer(2);
    
    int lcm = LCM(max(denom1, denom2), min(denom2, denom1));
    numer1 *= (lcm / denom1);
    numer2 *= (lcm / denom2);
    
    numer1 += numer2;
    int gcd = GCD(max(numer1, lcm), min(numer1, lcm));
    answer[0] = numer1 / gcd;
    answer[1] = lcm / gcd;
    
    return answer;
}
