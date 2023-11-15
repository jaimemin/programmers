#include <string>
#include <vector>
#include <iostream>
using namespace std;

const int MAX = 1e5 + 1;

const int FINAL_SCORE = 0;

typedef struct
{
    int cnt;
    int bullOrSingleCnt;
} State;

vector<State> cache;

bool isPossible(int nextTotal, int total)
{
    if (nextTotal < 0)
    {
        return false;
    }

    if (cache[nextTotal].cnt 
        && cache[nextTotal].cnt <= cache[total].cnt)
    {
        return false;
    }

    if (cache[nextTotal].cnt == cache[total].cnt + 1 
        && cache[nextTotal].bullOrSingleCnt > cache[total].bullOrSingleCnt)
    {
        return false;
    }
    
    return true;
}

vector<int> solution(int target) {
    cache.resize(target + 1, {0, 0});
    
    for (int total = target; total > 0; total--)
    {
        for (int multiple = 1; multiple <= 3; multiple++)
        {
            for (int score = 1; score <= (multiple == 1 ? 50 : 20); score += (multiple == 1 && score == 20) ? 30 : 1)
            {
                int nextTotal = total - (score * multiple);

                if (!isPossible(nextTotal, total))
                {
                    continue;
                }

                cache[nextTotal].cnt = cache[total].cnt + 1;
                cache[nextTotal].bullOrSingleCnt = (multiple == 1) 
                    ? cache[total].bullOrSingleCnt + 1 : cache[total].bullOrSingleCnt;
            }
        }
    }
    
    return {cache[FINAL_SCORE].cnt, cache[FINAL_SCORE].bullOrSingleCnt};
}
