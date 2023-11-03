#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

const int MAX = 1e5 + 1;

vector<int> graph[MAX];

vector<int> solution(int n, vector<vector<int>> roads, vector<int> sources, int destination) {
    for (vector<int> road : roads)
    {
        graph[road[0]].push_back(road[1]);
        graph[road[1]].push_back(road[0]);
    }
    
    vector<int> answer;
    
    for (int source : sources)
    {
        if (source == destination)
        {
            answer.push_back(0);
            
            continue;
        }
        
        bool canReach = false;
        bool visited[MAX] = {false,};
        queue<pair<int, int>> q;
        q.push({destination, 0});
        visited[destination] = true;
        
        while (!q.empty())
        {
            int cur = q.front().first;
            int dist = q.front().second;
            q.pop();
            
            if (cur == source)
            {
                answer.push_back(dist);
                canReach = true;
                
                break;
            }
            
            for (int next : graph[cur])
            {
                if (visited[next])
                {
                    continue;
                }
                
                visited[next] = true;
                q.push({next, dist + 1});
            }
        }
        
        if (!canReach)
        {
            answer.push_back(-1);
        }
    }
    
    return answer;
}
