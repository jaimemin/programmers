#include <string>
#include <vector>
#include <iostream>
using namespace std;

const int MAX = 17;

int answer = 0;

vector<int> graph[MAX];

bool visited[1 << MAX];

bool gameOver(int nodeCnt, int wolfCnt)
{
    return wolfCnt * 2 >= nodeCnt;
}

bool alreadyVisited(int bit, int node)
{
    return !(bit & (1 << node));
}

void func(int bit, vector<int> &info)
{
    if (visited[bit])
    {
        return;
    }
    
    visited[bit] = true;
    int wolfCnt = 0, nodeCnt = 0;
    
    for (int node = 0; node < info.size(); node++)
    {
        if (alreadyVisited(bit, node))
        {
            continue;
        }
        
        wolfCnt += info[node];
        nodeCnt++;
    }
    
    if (gameOver(nodeCnt, wolfCnt))
    {
        return;
    }
    
    answer = max(answer, nodeCnt - wolfCnt);
    
    for (int node = 0; node < info.size(); node++)
    {
        if (alreadyVisited(bit, node))
        {
            continue;
        }
        
        for (int next : graph[node])
        {
            func(bit | (1 << next), info);
        }
    }
}

int solution(vector<int> info, vector<vector<int>> edges) {
    for (vector<int> edge : edges)
    {
        graph[edge[0]].push_back(edge[1]);
    }

    func(1 << 0, info);
    
    return answer;
}
