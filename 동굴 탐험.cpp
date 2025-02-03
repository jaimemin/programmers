#include <string>
#include <vector>
#include <queue>
using namespace std;

bool solution(int n, vector<vector<int>> path, vector<vector<int>> order) {
    vector<vector<int>> graph(n);
    
    for (auto p : path) 
    {
        int u = p[0];
        int v = p[1];
        
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    
    // order 정보를 이용하여 각 방의 선행 조건 저장
    // pre[i] : i번 방을 방문하기 전에 반드시 방문해야 하는 방 번호 (없으면 -1)
    // waiting[i] : i번 방이 방문된 후에 방문이 가능해지는 방 (최대 1개, 없으면 -1)
    vector<int> pre(n, -1);
    vector<int> waiting(n, -1);
    
    for (auto ord : order) 
    {
        int prerequisite = ord[0];
        int dependent = ord[1];
        
        pre[dependent] = prerequisite;
    }
    
    // 시작 노드 0이 선행 조건을 가진다면 탐험 시작이 불가능
    if (pre[0] != -1) 
    {
        return false;
    }
    
    queue<int> q;
    q.push(0);
    
    vector<bool> visited(n, false);
    visited[0] = true;
    
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        
        // cur 노드를 방문함으로써, cur을 선행 조건으로 기다리던 방이 있다면 방문 가능
        if (waiting[cur] != -1)
        {
            int nextRoom = waiting[cur];
            
            q.push(nextRoom);
            visited[nextRoom] = true;
            waiting[cur] = -1;  // 대기 상태 해제
        }
        
        for (auto next : graph[cur])
        {
            if (visited[next]) 
            {
                continue;
            }
            
            // next를 방문하려면, next의 선행 조건이 방문되었어야 함
            if (pre[next] != -1 && !visited[ pre[next] ])
            {
                // 선행 조건이 아직 방문되지 않았다면, next는 cur의 선행 조건
                // 즉, pre[next]가 방문된 후에 방문하도록 대기
                waiting[pre[next]] = next;
                
                continue;
            }
            
            visited[next] = true;
            q.push(next);
        }
    }
    
    for (int i = 0; i < n; i++)
    {
        if (!visited[i]) 
        {
            return false;
        }
    }
    
    return true;
}
