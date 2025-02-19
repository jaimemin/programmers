#include <string>
#include <vector>
#include <cstring>
using namespace std;

const long long MOD = 1e9 + 7;

const int MAX = 1e2 + 1;

int solution(int n, int count) {
    long long dp[MAX][MAX] = {0, };
    dp[1][1] = 1;
    
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            dp[i + 1][j + 1] = (dp[i + 1][j + 1] + dp[i][j]) % MOD;
            dp[i + 1][j] = (dp[i + 1][j] + (dp[i][j] * (2LL * i)) % MOD) % MOD;
        }
    }
    
    return dp[n][count] % MOD;
}
