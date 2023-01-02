#include <string>
#include <vector>
#include <cmath>
#include <iostream>
using namespace std;

long long getOneCnt(int n, long long idx)
{
    long long cnt = 0;

    while (n != 1)
    {
        n--;
        long long oneCnt = pow(4, n);
        long long size = pow(5, n);

        if (idx > 3 * size)
        {
            cnt += 2 * oneCnt;
            idx -= 3 * size;
            cnt += (idx / size) * oneCnt;
            idx = idx % size;
        }
        else if (idx <= 2 * size)
        {
            cnt += (idx / size) * oneCnt;
            idx = idx % size;
        }
        else
        {
            cnt += 2 * oneCnt;

            return cnt;
        }
    }

    switch (idx)
    {
    case 1:
    case 2:
        cnt += idx;

        break;
    case 3:
    case 4:
    case 5:
        cnt += idx - 1;

        break;
    }

    return cnt;
}

int solution(int n, long long l, long long r) {
    return getOneCnt(n, r) - getOneCnt(n, l - 1);
}