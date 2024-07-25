#include <vector>
using namespace std;

const int MAX = 300 + 3;

const int MOD = 1e7 + 19;

long long arrOneCnts[MAX];

long long combination[MAX][MAX];

long long cache[MAX][MAX];

void init(vector<vector<int>> &a) 
{
    combination[0][0] = 1;
    
    for (int i = 1; i < MAX; i++) 
    {
        for (int j = 0; j < MAX; j++) 
        {
            if (j == 0 || i == j) 
            {
                combination[i][j] = 1;
                
                continue;
            } 
            
            combination[i][j] = combination[i - 1][j - 1] + combination[i - 1][j];
            combination[i][j] %= MOD;
        }
    }
    
    for (int i = 0; i < a.size(); i++) 
    {
        for (int j = 0; j < a[0].size(); j++) 
        {
            arrOneCnts[j] += a[i][j];
        }
    }
}

int solution(vector<vector<int>> a) {
    int row = a.size();
    int col = a[0].size();
    init(a);
    
    cache[1][row - arrOneCnts[0]] = combination[row][row - arrOneCnts[0]];

    for (int column = 1; column < col; column++) 
    {
        int oneCount = arrOneCnts[column];
        
        for (int evenNum = 0; evenNum <= row; evenNum++) 
        {
            if (cache[column][evenNum] == 0) 
            {
                continue;
            }
            
            for (int k = 0; k <= oneCount; k++)
            {
                if (evenNum < k) 
                {
                    continue;
                }
                
                int bEvenRow = evenNum + oneCount - 2 * k;
                
                if (bEvenRow > row) 
                {
                    continue;
                }
                
                long long result = (combination[evenNum][k] * combination[row - evenNum][oneCount - k]) % MOD;
                cache[column + 1][bEvenRow] = (cache[column + 1][bEvenRow] + cache[column][evenNum] * result) % MOD;
            }
        }
    }
    
    return cache[col][row];
}
