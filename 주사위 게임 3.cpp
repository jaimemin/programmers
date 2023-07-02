#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <iostream>
using namespace std;

set<int> nums;
map<int, int> num2cnt;

void init(int a, int b, int c, int d)
{
    num2cnt[a]++;
    num2cnt[b]++;
    num2cnt[c]++;
    num2cnt[d]++;
    nums.insert(a);
    nums.insert(b);
    nums.insert(c);
    nums.insert(d);
}

int solution(int a, int b, int c, int d) {
    init(a, b, c, d);
    int answer = 1;
    int p, q;

    switch (nums.size())
    {
    case 1:
        answer = a * 1111;

        break;
    case 2:
        p = *nums.begin();
        q = *nums.rbegin();

        if (num2cnt[p] != 2)
        {
            answer = (10 * (num2cnt[p] == 3 ? p : q) + (num2cnt[p] == 3 ? q : p));
            answer *= answer;
        }
        else
        {
            answer = (p + q) * abs(p - q);
        }

        break;
    case 3:
        for (int num : nums)
        {
            if (num2cnt[num] != 2)
            {
                answer *= num;
            }
        }

        break;
    case 4:
        answer = min({ a, b, c, d });

        break;
    }

    return answer;
}