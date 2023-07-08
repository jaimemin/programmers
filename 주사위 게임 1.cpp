#include <string>
#include <vector>
#include <cmath>
using namespace std;

int solution(int a, int b) {
    int answer = 0;

    if (a % 2 && b % 2)
    {
        answer = a * a + b * b;
    }
    else if (a % 2 == 0 && b % 2 == 0)
    {
        answer = abs(a - b);
    }
    else
    {
        answer = 2 * (a + b);
    }

    return answer;
}