#include <string>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAX = 150 + 15;

const int INF = 987654321;

int maxAlpReq = 0;

int maxCopReq = 0;

int cache[MAX][MAX];

void init(void)
{
    for (int i = 0; i < MAX; i++)
    {
        for (int j = 0; j < MAX; j++)
        {
            cache[i][j] = INF; 
        }
    }
}

int func(int alp, int cop, vector<vector<int>> &problems)
{
    if (maxAlpReq <= alp && maxCopReq <= cop)
    {
        return 0;
    }
    
    int &result = cache[alp][cop];
    
    if (result != -1)
    {
        return result;
    }
    
    result = INF;
    result = min(result, func(min(maxAlpReq, alp + 1), cop, problems) + 1);
    result = min(result, func(alp, min(maxCopReq, cop + 1), problems) + 1);
    
    for (vector<int> problem : problems)
    {
        if (alp < problem[0] || cop < problem[1])
        {
            continue;
        }
        
        result = min(result, func(min(maxAlpReq, alp + problem[2]), min(maxCopReq, cop + problem[3]), problems) + problem[4]);
    }
    
    return result;
}

int solution(int alp, int cop, vector<vector<int>> problems) {
    memset(cache, -1, sizeof(cache));
    
    for (vector<int> problem : problems) {
        maxAlpReq = max(maxAlpReq, problem[0]);
        maxCopReq = max(maxCopReq, problem[1]);
    }
    
    return func(alp, cop, problems);
}
