#include <string>
#include <vector>

using namespace std;

const long long MOD = 1e9 + 7;

vector<vector<long long>> multiply(vector<vector<long long>> A, vector<vector<long long>> B) 
{
    int n = A.size();
    vector<vector<long long>> C(n, vector<long long>(n, 0));
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            long long sum = 0;
            
            for (int k = 0; k < n; k++)
            {
                sum = (sum + A[i][k] * B[k][j]) % MOD;
            }
            
            C[i][j] = sum % MOD;
        }
    }
    
    return C;
}

vector<vector<long long>> power(vector<vector<long long>> base, long long exp) 
{
    int n = base.size();
    vector<vector<long long>> result(n, vector<long long>(n, 0));
    
    for (int i = 0; i < n; i++)
    {
        result[i][i] = 1;
    }
    
    while (exp > 0)
    {
        if (exp % 2)
        {
            result = multiply(result, base);
        }
        
        base = multiply(base, base);
        exp /= 2;
    }
    
    return result;
}

int solution(vector<vector<int>> grid, vector<int> d, int k) {
    int n = grid.size();
    int m = grid[0].size();
    int totalCell = n * m;
    int slopeSize = d.size();
 
    // M[u][v]는 u번 칸에서 d 수열 한 번을 수행하여 v번 칸에 도착하는 경로의 수
    vector<vector<long long>> M(totalCell, vector<long long>(totalCell, 0));
    
    for (int start = 0; start < totalCell; start++)
    {
        // dp[x] : 현재 단계에서 격자 내 x번 칸에 도달하는 경로의 수
        vector<long long> dp(totalCell, 0);
        dp[start] = 1;
        
        for (int step = 0; step < slopeSize; step++)
        {
            vector<long long> newDp(totalCell, 0);
            
            for (int cell = 0; cell < totalCell; cell++)
            {
                if (dp[cell] == 0)
                {
                    continue;
                }
                
                int r = cell / m;
                int c = cell % m;

                if (r - 1 >= 0)
                {
                    int nextR = r - 1;
                    int nextC = c;

                    if (grid[nextR][nextC] - grid[r][c] == d[step])
                    {
                        newDp[nextR * m + nextC] = (newDp[nextR * m + nextC] + dp[cell]) % MOD;
                    }
                }

                if (r + 1 < n)
                {
                    int nextR = r + 1;
                    int nextC = c;

                    if (grid[nextR][nextC] - grid[r][c] == d[step])
                    {
                        newDp[nextR * m + nextC] = (newDp[nextR * m + nextC] + dp[cell]) % MOD;
                    }
                }

                if (c - 1 >= 0)
                {
                    int nextR = r;
                    int nextC = c - 1;

                    if (grid[nextR][nextC] - grid[r][c] == d[step])
                    {
                        newDp[nextR * m + nextC] = (newDp[nextR * m + nextC] + dp[cell]) % MOD;
                    }
                }

                if (c + 1 < m)
                {
                    int nextR = r;
                    int nextC = c + 1;

                    if (grid[nextR][nextC] - grid[r][c] == d[step])
                    {
                        newDp[nextR * m + nextC] = (newDp[nextR * m + nextC] + dp[cell]) % MOD;
                    }
                }
            }
            
            dp = newDp;
        }
        
        // d 수열 하나를 수행 후 각 최종 상태 v에 도착하는 경로의 수를 전이 행렬에 기록
        for (int v = 0; v < totalCell; v++)
        {
            M[start][v] = dp[v] % MOD;
        }
    }
    
    // 전체 경로는 d 수열을 k번 반복
    vector<vector<long long>> Mk = power(M, k);
    
    long long answer = 0;
    
    for (int i = 0; i < totalCell; i++)
    {
        for (int j = 0; j < totalCell; j++)
        {
            answer = (answer + Mk[i][j]) % MOD;
        }
    }
    
    return (int) answer;
}
