#include <vector>
#include <algorithm>
#include <queue>
#include <climits>
using namespace std;

const long long INF = LLONG_MAX;

const int MAX = 3000 + 30;

int N;

vector<pair<int,int>> graph[MAX];

// money 범위가 0 ~ limit, city 범위가 0 ~ (N - 1) 이므로
// 인덱스를 "money * N + city" 형태로 치환
int getIdx(int money, int city)
{
    return money * N + city;
}

vector<long long> solution(int n, int z, vector<vector<int>> roads, vector<long long> queries) {
    N = n;
    
    for (auto rd : roads)
    {
        int u = rd[0];
        int v = rd[1];
        int w = rd[2];
        
        graph[u].push_back({v, w});
    }

    int limit = z * z + z;

    // dist[(money, city)] = 해당 (money, city) 상태를 달성하는 데 필요한 최소 턴 수
    vector<int> dist((limit + 1) * n, -1);
    // 순간이동 액션 최적화를 위한 배열
    // visitedTeleport[m] = "money = m"인 상태에서
    // 현재 BFS 층(level)에서 순간이동을 이미 처리했는지 여부 (-1이면 아직, 아니면 그 BFS 층)
    vector<int> visitedTeleport(limit + 1, -1);

    queue<pair<int,int>>q; 
    dist[getIdx(0, 0)] = 0;
    q.push({0, 0});

    while (!q.empty())
    {
        auto [curMoney, curCity] = q.front();
        q.pop();
        int curDist = dist[getIdx(curMoney, curCity)];

        // 1) 가만히 있기: money + z
        int nxt = curMoney + z;
        
        if (nxt <= limit)
        {
            int &dref = dist[getIdx(nxt, curCity)];
            
            if (dref == -1)
            {
                dref = curDist + 1;
                q.push({nxt, curCity});
            }
        }
        // 1) 가만히 있기: money + z

        // 2) 도로 이용: city에서 갈 수 있는 도시(v)로 이동, money + w
        for (auto edge : graph[curCity])
        {
            int v = edge.first;
            int w = edge.second;
            int nxt = curMoney + w;
            
            if (nxt <= limit)
            {
                int &dref = dist[getIdx(nxt, v)];
                
                if (dref == -1)
                {
                    dref = curDist + 1;
                    
                    q.push({nxt, v});
                }
            }
        }
        // 2) 도로 이용: city에서 갈 수 있는 도시(v)로 이동, money + w

        // 3) 순간이동: (curMoney, curCity)에서 같은 money로 다른 모든 도시로 이동
        //    하지만 매번 모든 도시로 순간이동을 확장하면 너무 비효율적이므로,
        //    "현재 BFS 레벨 curDist에서 money=curMoney인 상태"에 대해 단 한 번만 처리
        if (visitedTeleport[curMoney] != curDist)
        {
            // 아직 curDist 레벨에서 순간이동 확장을 안 했다면, 이제 수행
            visitedTeleport[curMoney] = curDist;

            for (int t = 0; t < n; t++)
            {
                if (t == curCity) 
                {
                    continue;
                }
                
                int &dref = dist[getIdx(curMoney, t)];
                
                if (dref == -1)
                {
                    dref = curDist + 1;
                    
                    q.push({curMoney, t});
                }
            }
        }
        // 3) 순간이동: (curMoney, curCity)에서 같은 money로 다른 모든 도시로 이동
    }

    // BFS가 끝나면, dp[x] = "정확히 x원을 달성하는 데 필요한 최소 턴"
    // city는 상관없이 어떤 city에 있어도 되므로,
    // dist[x, city] 중 최솟값이 dp[x]가 됨
    vector<long long> dp(limit + 1, LLONG_MAX);
    
    for (int x = 0; x <= limit; x++)
    {
        long long best = LLONG_MAX;
        
        for (int c = 0; c < n; c++)
        {
            int dval = dist[getIdx(x,c)];
            
            if (dval >= 0)
            {
                if (best > dval)
                {
                    best = dval;
                }
            }
        }
        
        if (best < LLONG_MAX) 
        {
            dp[x] = best;
        }
    }

    vector<long long> answer;

    for (long long c : queries)
    {
        // 1. c == 0 인 경우는 이미 0원 상태에서 시작하므로 0턴
        if (c == 0)
        {
            answer.push_back(0LL);
            
            continue;
        }

        // 2. c > 0 인 경우
        long long bestAns = -1;
        long long K = c / z;
        // k를 K에서 최대 z 정도 줄여보면서 leftover를 dp로 만들 수 있는지 확인
        // (여유분 -2는 혹시 모를 경계 효과를 위해 조금 더 잡은 것)
        long long lowK = max(0LL, K - z - 2); 

        for (long long k = K; k >= lowK; k--)
        {
            long long leftover = c - k * z;
            
            if (leftover < 0)
            {
                break;
            }
            
            if (leftover > limit) 
            {
                continue;
            }
            
            if (dp[leftover] == LLONG_MAX)
            {
                continue;
            }
            
            // candidate = k(= stay-put 횟수) + dp[leftover]
            //   -> leftover를 만드는 최소턴(dp[leftover]) + 남은 금액은 stay-put(k회)
            long long cand = k + dp[leftover];
            
            if (bestAns < 0 || cand < bestAns)
            {
                bestAns = cand;
            }
        }

        answer.push_back(bestAns);
    }

    return answer;
}
