#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int MAX = 25 * 25 + 25;

const int INF = 987654321;

typedef struct
{
    int y, x;
} Dir;

Dir moveDir[4] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

struct State
{
    int y, x;
    int cost;
    int prevDir;
};

bool operator<(State a, State b)
{
    return a.cost > b.cost;
}

int solution(vector<vector<int>> board) {
    int answer = -1;
    int N = board.size();
    
    priority_queue<State> pq;
    pq.push({0, 0, 0, -1});
    int visited[MAX][MAX] = { 0, };
    
    for (int i = 0; i < MAX; i++)
    {
        for (int j = 0; j < MAX; j++)
        {
            visited[i][j] = INF;
        }
    }
    
    while (!pq.empty())
    {
        State cur = pq.top();
        int y = cur.y;
        int x = cur.x;
        int cost = cur.cost;
        int prevDir = cur.prevDir;
        pq.pop();
        
        if (y == N - 1 && x == N - 1)
        {
            return cost;
        }
        
        for (int k = 0; k < 4; k++) 
        {
            int nextY = y + moveDir[k].y;
            int nextX = x + moveDir[k].x;
            
            if (nextY < 0 || nextY >= N || nextX < 0 || nextX >= N || board[nextY][nextX])
            {
                continue;
            }
            
            int nextCost = prevDir == -1 || prevDir == k ? cost + 100 : cost + 600;
            
            if (prevDir != -1 && visited[25 * y + x][25 * nextY + nextX] <= nextCost)
            {
                continue;
            }
            
            visited[25 * y + x][25 * nextY + nextX] = nextCost;
            visited[25 * nextY + nextX][25 * y + x] = nextCost;
            pq.push({nextY, nextX, nextCost, k});
        }
    }
    
    return answer;
}
