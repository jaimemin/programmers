#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int MAX = 100;

typedef struct
{
    int y, x;
} Dir;

Dir moveDir[4] = {{ 1, 0 }, { -1, 0 }, { 0, 1 }, { 0, -1}};

bool visited[MAX][MAX];

vector<int> solution(vector<string> maps) {
    vector<int> answer;
    
    for (int y = 0; y < maps.size(); y++)
    {
        for (int x = 0; x < maps[y].size(); x++)
        {
            if (maps[y][x] == 'X' || visited[y][x])
            {
                continue;
            }
            
            queue<pair<int, int>> q;
            q.push({y, x});
            visited[y][x] = true;
            int sum = maps[y][x] - '0';
            
            while (!q.empty())
            {
                int y = q.front().first;
                int x = q.front().second;
                q.pop();
                
                for (int k = 0; k < 4; k++)
                {
                    int nextY = y + moveDir[k].y;
                    int nextX = x + moveDir[k].x;
                    
                    if (nextY < 0 || nextY >= maps.size())
                    {
                        continue;
                    }
                    
                    if (nextX < 0 || nextX >= maps[0].size())
                    {
                        continue;
                    }
                    
                    if (visited[nextY][nextX] || maps[nextY][nextX] == 'X')
                    {
                        continue;
                    }
                    
                    visited[nextY][nextX] = true;
                    sum += maps[nextY][nextX] - '0';
                    
                    q.push({ nextY, nextX });
                }
            }
            
            answer.push_back(sum);
        }
    }
    
    sort(answer.begin(), answer.end());
    
    if (answer.empty())
    {
        answer.push_back(-1);
    }
    
    return answer;
}
