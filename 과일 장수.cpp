#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(int k, int m, vector<int> score) {
    sort(score.begin(), score.end());

    int answer = 0;
    int cnt = 0;

    for (int i = score.size() - 1; i >= 0; i--)
    {
        if (++cnt == m)
        {
            answer += score[i] * m;

            cnt = 0;
        }
    }

    return answer;
}