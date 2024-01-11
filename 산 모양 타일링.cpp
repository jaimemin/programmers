#include <string>
#include <vector>

using namespace std;

const int MAX = 1e5 + 10;

const int MOD = 1e4 + 7;

int cache[MAX][2];

int solution(int n, vector<int> tops) {
    cache[0][0] = 1;
    
    for (int i = 0; i < n; i++)
    {
        cache[i + 1][0] = cache[i][0] * (2 + tops[i]) + cache[i][1] * (1 + tops[i]);
        cache[i + 1][1] = cache[i][0] + cache[i][1];
        
        cache[i + 1][0] %= MOD;
        cache[i + 1][1] %= MOD;
    }
    
    return (cache[n][0] + cache[n][1]) % MOD;
}
