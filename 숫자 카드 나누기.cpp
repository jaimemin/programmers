#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int GCD(int a, int b)
{
    if (a % b == 0)
    {
        return b;
    }

    return GCD(b, a % b);
}

int solution(vector<int> arrayA, vector<int> arrayB) {
    sort(arrayA.begin(), arrayA.end());
    sort(arrayB.begin(), arrayB.end());

    int answer = 0;
    int aGCD = arrayA[0];
    int bGCD = arrayB[0];

    for (int a : arrayA)
    {
        aGCD = GCD(aGCD, a);
    }

    for (int b : arrayB)
    {
        bGCD = GCD(bGCD, b);
    }

    bool flag = true;

    for (int a : arrayA)
    {
        if (a % bGCD == 0)
        {
            flag = false;

            break;
        }
    }

    if (flag)
    {
        answer = max(answer, bGCD);
    }

    flag = true;

    for (int b : arrayB)
    {
        if (b % aGCD == 0)
        {
            flag = false;

            break;
        }
    }

    if (flag)
    {
        answer = max(answer, aGCD);
    }

    return answer;
}