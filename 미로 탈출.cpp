#include <string>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

const int MAX = 100;

typedef struct
{
    int y, x;
    int time;
    bool lever;
} State;

bool operator<(State a, State b)
{
    return a.time > b.time;
}

typedef struct
{
    int y, x;
} Dir;

Dir moveDir[4] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };

bool visited[MAX][MAX];

int solution(vector<string> maps) {
    priority_queue<State> pq, pqAfterLever;
    
    for (int y = 0; y < maps.size(); y++)
    {
        for (int x = 0; x < maps[0].size(); x++)
        {
            if (maps[y][x] == 'S')
            {
                pq.push({ y, x, 0, false });
                
                visited[y][x] = true;
            }
        }
    }
    
    // 시작점에서 레버
    while (!pq.empty())
    {
        int y = pq.top().y;
        int x = pq.top().x;
        int time = pq.top().time;
        bool lever = pq.top().lever;
        pq.pop();
        
        if (lever)
        {
            pqAfterLever.push({ y, x, time, true });
            
            break;
        }
        
        for (int k = 0; k < 4; k++)
        {
            int nextY = y + moveDir[k].y;
            int nextX = x + moveDir[k].x;
            
            if (nextY < 0 || nextY >= maps.size() || nextX < 0 || nextX >= maps[0].size())
            {
                continue;
            }
            
            if (visited[nextY][nextX] || maps[nextY][nextX] == 'X')
            {
                continue;
            }
            
            if (maps[nextY][nextX] == 'L')
            {
                lever = true;
            }
            
            visited[nextY][nextX] = true;
            pq.push({ nextY, nextX, time + 1, lever });
        }
    }
    
    memset(visited, false, sizeof(visited));
    
    // 레버에서 도착점
    while (!pqAfterLever.empty())
    {
        int y = pqAfterLever.top().y;
        int x = pqAfterLever.top().x;
        int time = pqAfterLever.top().time;
        bool lever = pqAfterLever.top().lever;
        pqAfterLever.pop();
        
        if (maps[y][x] == 'E')
        {
            return time;
        }
        
        for (int k = 0; k < 4; k++)
        {
            int nextY = y + moveDir[k].y;
            int nextX = x + moveDir[k].x;
            
            if (nextY < 0 || nextY >= maps.size() || nextX < 0 || nextX >= maps[0].size())
            {
                continue;
            }
            
            if (visited[nextY][nextX] || maps[nextY][nextX] == 'X')
            {
                continue;
            }
            
            visited[nextY][nextX] = true;
            pqAfterLever.push({ nextY, nextX, time + 1, lever });
        }
    }
    
    return -1;
}
