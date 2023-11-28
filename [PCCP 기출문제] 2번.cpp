#include <string>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>
using namespace std;

const int MAX = 500 + 5;

typedef struct
{
    int y, x;
} Dir;

Dir moveDir[4] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

bool visited[MAX][MAX];

int maxOil[MAX];

int solution(vector<vector<int>> land) {
    int N = land.size();
    int M = land[0].size();
    
    for (int y = 0; y < N; y++)
    {
        for (int x = 0; x < M; x++)
        {
            if (!land[y][x] || visited[y][x])
            {
                continue;
            }
            
            set<int> xSet;
            queue<pair<int, int>> q;
            q.push({y, x});
            visited[y][x] = true;
            int cnt = 0;
            
            while (!q.empty())
            {
                int curY = q.front().first;
                int curX = q.front().second;
                xSet.insert(curX);
                cnt++;
                q.pop();
                
                for (int k = 0; k < 4; k++)
                {
                    int nextY = curY + moveDir[k].y;
                    int nextX = curX + moveDir[k].x;
                    
                    if (nextY < 0 || nextY >= N || nextX < 0 || nextX >= M)
                    {
                        continue;
                    }
                    
                    if (visited[nextY][nextX] || !land[nextY][nextX])
                    {
                        continue;
                    }
                    
                    visited[nextY][nextX] = true;
                    q.push({nextY, nextX});
                }
            }
            
            for (int x : xSet)
            {
                maxOil[x] += cnt;
            }
        }
    }
    
    sort(maxOil, maxOil + MAX);
    
    return maxOil[MAX - 1];
}
