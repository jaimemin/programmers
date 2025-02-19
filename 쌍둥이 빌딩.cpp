#include <vector>
#include <string>

using namespace std;

const long long MOD = 1e9 + 7;

const int MAX = 205;

long long nestedPairCount[MAX];

long long splitPairCount[MAX];

long long dp[MAX][MAX];

long long combination[MAX][MAX];

void init() 
{
    for (int i = 0; i < MAX; i++)
    {
        for (int j = 0; j <= i; j++) 
        {
            if(j == 0 || j == i)
            {
                combination[i][j] = 1;
            }
            else
            {
                combination[i][j] = (combination[i - 1][j - 1] + combination[i - 1][j]) % MOD;
            }
        }
    }
}
 
long long getCombination(int n, int r) 
{
    if (r < 0 || r > n) 
    {
        return 0;
    }
    
    return combination[n][r];
}

int solution(int n, int count) {
    init();

    nestedPairCount[0] = 1;
    
    for (int i = 1; i <= n; i++)
    {
        long long mul = (2LL * i - 1) % MOD;
        
        nestedPairCount[i] = (nestedPairCount[i - 1] * mul) % MOD;
    }

    for (int i = 0; i <= n; i++)
    {
        long long sum = 0;
        
        for (int j = 0; j <= i; j++)
        {
            long long term = getCombination(i, j);
            term = (term * nestedPairCount[j]) % MOD;
            term = (term * nestedPairCount[i - j]) % MOD;
            
            sum = (sum + term) % MOD;
        }
        
        splitPairCount[i] = sum % MOD;
    }

    dp[0][0] = 1;
    dp[1][1] = 1;
    
    for (int i = 2; i <= n; i++)
    {
        int lowerCount = i - 1;
        dp[i][1] = splitPairCount[lowerCount] % MOD;
        
        for (int j = 2; j <= i; j++)
        {
            long long ways = 0;
            
            for (int a = 1; a <= lowerCount; a++)
            {
                long long choose = getCombination(lowerCount, a);
                long long leftPart = dp[a][j - 1];
                long long rest = splitPairCount[lowerCount - a];
                long long part = ((choose * leftPart) % MOD * rest) % MOD;
                
                ways = (ways + part) % MOD;
            }
            
            dp[i][j] = ways % MOD;
        }
    }
    
    return (int)(dp[n][count] % MOD);
}
