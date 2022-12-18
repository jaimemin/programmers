#include <string>
#include <vector>
using namespace std;

int getSevenCnt(int num)
{
    int cnt = 0;

    while (num)
    {
        cnt += num % 10 == 7 ? 1 : 0;

        num /= 10;
    }

    return cnt;
}

int solution(vector<int> array) {
    int answer = 0;

    for (int num : array)
    {
        answer += getSevenCnt(num);
    }

    return answer;
}