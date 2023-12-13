#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <cstring>
using namespace std;

const int MAX = 1e5 + 1;

set<int> lights;
set<int> pathes[MAX];
bool visited[MAX];

bool isLeafNode(int node)
{
    return pathes[node].size() == 1;
}

void func(int node)
{
    if (isLeafNode(node))
    {
        return;
    }
    
    visited[node] = true;
    bool lightUp = false;
    
    for (int next : pathes[node])
    {
        if (visited[next])
        {
            continue;
        }
        
        func(next);
        
        if (!lights.count(next))
        {
            lightUp = true;   
        }
    }
    
    if (lightUp)
    {
        lights.insert(node);
    }
}

int solution(int n, vector<vector<int>> lighthouse) {
    if (lighthouse.size() == 1)
    {
        return 1;
    }
    
    int highest = 0;
    
    for (vector<int> path : lighthouse)
    {
        highest = max({highest, path[0], path[1]});
        
        pathes[path[0]].insert(path[1]);
        pathes[path[1]].insert(path[0]);
    }
    
    for (int node = 1; node <= highest; node++)
    {
        if (isLeafNode(node))
        {
            continue;
        }
        
        memset(visited, sizeof(visited), false);
        func(node);
    }

    return lights.size();
}
