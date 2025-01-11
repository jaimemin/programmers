#include <vector>
#include <algorithm>
#include <limits>
#include <cstring>
using namespace std;

const int MAXN = 101;

vector<int> children1[MAXN], children2[MAXN];

int dp[MAXN][MAXN];

int hungarian(const vector<vector<int>>& cost) 
{
    int n = cost.size();
    
    if (n == 0) 
    {
        return 0;
    }
    
    int m = cost[0].size();
    
    if (m == 0) 
    {
        return 0;
    }
    
    vector<vector<int>> mc(n, vector<int>(m));
    
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            mc[i][j] = -cost[i][j];
        }
    }

    int size = max(n, m);
    vector<vector<int>> a(size, vector<int>(size, 0));
    
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            a[i][j] = mc[i][j];
        }
    }

    vector<int> u(size+1), v(size+1), p(size+1), way(size+1);

    for(int i = 1; i <= size; i++)
    {
        p[0] = i;
        int j0 = 0;
        vector<int> minv(size+1, numeric_limits<int>::max());
        vector<bool> used(size+1, false);

        do 
        {
            used[j0] = true;
            int i0 = p[j0], j1 = 0;
            int delta = numeric_limits<int>::max();
            
            for(int j = 1; j <= size; j++)
            {
                if(!used[j])
                {
                    int cur = a[i0-1][j-1] - u[i0] - v[j];
                    
                    if(cur < minv[j])
                    {
                        minv[j] = cur;
                        way[j] = j0;
                    }
                    
                    if(minv[j] < delta)
                    {
                        delta = minv[j];
                        j1 = j;
                    }
                }
            }
            
            for(int j = 0; j <= size; j++)
            {
                if (used[j])
                {
                    u[p[j]] += delta;
                    v[j] -= delta;
                } 
                else 
                {
                    minv[j] -= delta;
                }
            }
            
            j0 = j1;
        } while (p[j0] != 0);

        do 
        {
            int j1 = way[j0];
            p[j0] = p[j1];
            j0 = j1;
        } while(j0);
    }

    int res = 0;
    
    for(int j = 1; j <= size; j++)
    {
        int i = p[j];
        
        if(i >= 1 && i <= n 
           && j >= 1 && j <= m)
        {
            res += -a[i-1][j-1];
        }
    }
    
    return res;
}

int solveDP(int u, int v) 
{
    if(dp[u][v] != -1) 
    {
        return dp[u][v];
    }
    
    vector<int>& cU = children1[u];
    vector<int>& cV = children2[v];

    if (cU.empty() && cV.empty())
    {
        dp[u][v] = 1;
        
        return dp[u][v];
    }

    if (cU.empty() || cV.empty())
    {
        dp[u][v] = 1;
        
        return dp[u][v];
    }

    int szU = (int)cU.size();
    int szV = (int)cV.size();
    vector<vector<int>> cost(szU, vector<int>(szV, 0));

    for(int i = 0; i < szU; i++)
    {
        for(int j = 0; j < szV; j++)
        {
            cost[i][j] = solveDP(cU[i], cV[j]);
        }
    }

    int bestMatchSum = hungarian(cost);
    dp[u][v] = 1 + bestMatchSum;
    
    return dp[u][v];
}

void makeTreeDFS(int cur, int par, const vector<vector<int>>& adj, vector<int> children[]) 
{
    for(int nxt : adj[cur])
    {
        if(nxt == par) 
        {
            continue;
        }

        children[cur].push_back(nxt);
        makeTreeDFS(nxt, cur, adj, children);
    }
}

int solution(int n1, vector<vector<int>> g1, int n2, vector<vector<int>> g2) {
    for(int i = 0; i < MAXN; i++)
    {
        children1[i].clear();
        children2[i].clear();
    }
    
    memset(dp, -1, sizeof(dp));
    vector<vector<int>> adj1(n1+1), adj2(n2+1);

    for (auto &e : g1)
    {
        int a = e[0];
        int b = e[1];
        
        adj1[a].push_back(b);
        adj1[b].push_back(a);
    }

    for (auto &e : g2)
    {
        int a = e[0];
        int b = e[1];
        
        adj2[a].push_back(b);
        adj2[b].push_back(a);
    }

    makeTreeDFS(1, -1, adj1, children1);
    makeTreeDFS(1, -1, adj2, children2);

    return solveDP(1, 1);
}
