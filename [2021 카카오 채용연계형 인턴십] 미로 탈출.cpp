#include <string>
#include <vector>
#include <queue>
#include <limits>
using namespace std;
 
const long long INF = 1e18;

const int MAX = 1e3 + 1;
 
// 상태 구조체 : cost(누적 이동시간), node(현재 방), mask(함정 상태 bitmask)
typedef struct 
{
    long long cost;
    int node;
    int mask;
} State;
 
bool operator<(State a, State b)
{
    return a.cost > b.cost;
}

vector<pair<int, int>> graph[MAX];

vector<pair<int, int>> reverseGraph[MAX];
 
int solution(int n, int start, int end, vector<vector<int>> roads, vector<int> traps) {
    // traps에 포함된 방 번호에 대해 각 방을 bitmask의 몇 번째 비트에 매핑할지 결정
    int trapCnt = traps.size();
    vector<int> trap2idx(n + 1, -1);
    
    for (int i = 0; i < trapCnt; i++)
    {
        trap2idx[traps[i]] = i;
    }
    
    for (auto road : roads)
    {
        int u = road[0];
        int v = road[1];
        int w = road[2];
        
        graph[u].push_back({v, w});
        reverseGraph[v].push_back({u, w});
    }
    
    // dist[node][mask] : 현재 방 'node'에 trap상태 'mask'로 도착했을 때 최소 이동시간
    vector<vector<long long>> dist(n + 1, vector<long long>(1 << trapCnt, INF));
    dist[start][0] = 0;
    
    priority_queue<State> pq;
    pq.push({0, start, 0});
    
    while (!pq.empty())
    {
        State curState = pq.top();
        pq.pop();
        
        long long curCost = curState.cost;
        int curNode = curState.node;
        int mask = curState.mask;
 
        // 도착 방에 도달하면, 현재까지의 최소 비용이 답
        if (curNode == end)
        {
            return curCost;
        }
        
        if (curCost > dist[curNode][mask])
        {
            continue;
        }
        
        // 현재 방(curNode)이 함정이라면 현재 mask에서 활성여부를 확인
        bool curActivated = false;
        
        if (trap2idx[curNode] != -1)
        {
            if (mask & (1 << trap2idx[curNode])) 
            {
                curActivated = true;
            }
        }
 
        // 원래 curNode에서 나가는 edge (graph[curNode]) 확인
        // 원래 edge (cur->next)는, 현재 상태에서 cur와 nxt의 활성 여부가 같을 때 유효
        for (auto edge : graph[curNode])
        {
            int next = edge.first;
            int w = edge.second;
            bool nextActivated = false;
            
            if (trap2idx[next] != -1)
            {
                if (mask & (1 << trap2idx[next])) 
                {
                    nextActivated = true;
                }
            }
            
            if (curActivated == nextActivated)
            {
                int nextMask = mask;
                
                // 도착 방이 함정이면, 상태 토글
                if (trap2idx[next] != -1)
                {
                    nextMask = mask ^ (1 << trap2idx[next]);
                }
                
                if (dist[next][nextMask] > curCost + w)
                {
                    dist[next][nextMask] = curCost + w;
                    
                    pq.push({curCost + w, next, nextMask});
                }
            }
        }
 
        // 원래 다른 노드에서 curNode로 들어오는 edge (reverseGraph[curNode]) 확인
        // 이 경우, 원래 edge는 (next -> cur)이지만, 현재 상태에서 방향이 뒤집혀 cur->next로
        // 갈 수 있으려면 cur와 next의 활성 여부가 달라야 함
        for (auto edge : reverseGraph[curNode])
        {
            int next = edge.first;
            int w = edge.second;
            bool nextActivated = false;
            
            if (trap2idx[next] != -1)
            {
                if (mask & (1 << trap2idx[next])) 
                {
                    nextActivated = true;
                }
            }
 
            if (curActivated != nextActivated)
            {
                int nextMask = mask;
                
                if (trap2idx[next] != -1)
                { 
                    nextMask = mask ^ (1 << trap2idx[next]);
                }
                
                if (dist[next][nextMask] > curCost + w)
                {
                    dist[next][nextMask] = curCost + w;
                    
                    pq.push({curCost + w, next, nextMask});
                }
            }
        }
    }
    
    return -1;
}
