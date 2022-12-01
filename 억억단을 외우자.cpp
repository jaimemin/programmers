#include <string>
#include <vector>
#include <map>
#include <set>
#include <iostream>
using namespace std;

int getDivisorCnt(int number)
{
    map<int, int> divisor2cnt;
    set<int> divisors;

    for (int i = 2; i * i <= number; i++)
    {
        while (number % i == 0)
        {
            divisor2cnt[i]++;
            divisors.insert(i);

            number /= i;
        }
    }

    if (number != 1)
    {
        divisor2cnt[number]++;
        divisors.insert(number);
    }

    int cnt = 1;

    for (int divisor : divisors)
    {
        cnt *= (divisor2cnt[divisor] + 1);
    }

    return cnt;
}

vector<int> solution(int e, vector<int> starts) {
    vector<pair<int, int>> cache(e + 1, { 0, 0 });
    cache[e] = { getDivisorCnt(e), e };

    for (int i = e - 1; i >= 1; i--)
    {
        int divisorCnt = getDivisorCnt(i);

        if (divisorCnt >= cache[i + 1].first)
        {
            cache[i] = { divisorCnt, i };
        }
        else
        {
            cache[i] = cache[i + 1];
        }
    }

    vector<int> answer;

    for (int start : starts)
    {
        answer.push_back(cache[start].second);
    }

    return answer;
}