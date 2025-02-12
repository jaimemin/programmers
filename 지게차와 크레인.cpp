#include <string>
#include <vector>
#include <queue>

using namespace std;

typedef struct
{
    int y, x;
} Dir;

Dir moveDir[4] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int solution(vector<string> storage, vector<string> requests) {
    int n = storage.size();
    int m = storage[0].size();
    
    for (auto req : requests) 
    {
        char letter = req[0];
        
        if (req.size() == 2) 
        {
            for (int y = 0; y < n; y++)
            {
                for (int x = 0; x < m; x++)
                {
                    if (storage[y][x] == letter) 
                    {
                        storage[y][x] = '.';
                    }
                }
            }
            
            continue;
        }
        
        vector<vector<bool>> reachable(n, vector<bool>(m, false));
        queue<pair<int,int>> q;

        for (int y = 0; y < n; y++) 
        {
            if (storage[y][0] == '.' && !reachable[y][0]) 
            {
                reachable[y][0] = true;
                
                q.push({y, 0});
            }
            
            if (storage[y][m - 1] == '.' && !reachable[y][m - 1]) 
            {
                reachable[y][m - 1] = true;
                
                q.push({y, m - 1});
            }
        }
        
        for (int x = 0; x < m; x++)
        {
            if (storage[0][x] == '.' && !reachable[0][x]) 
            {
                reachable[0][x] = true;
                
                q.push({0, x});
            }
            
            if (storage[n - 1][x] == '.' && !reachable[n - 1][x]) 
            {
                reachable[n - 1][x] = true;
                
                q.push({n - 1, x});
            }
        }

        while (!q.empty())
        {
            auto cur = q.front(); 
            q.pop();
            
            int y = cur.first;
            int x = cur.second;
            
            for (int k = 0; k < 4; k++)
            {
                int nextY = y + moveDir[k].y;
                int nextX = x + moveDir[k].x;
                
                if (nextY < 0 || nextY >= n || nextX < 0 || nextX >= m)
                {
                    continue;
                }
                
                if (storage[nextY][nextX] == '.' && !reachable[nextY][nextX])
                {
                    reachable[nextY][nextX] = true;
                    
                    q.push({nextY, nextX});
                }
            }
        }

        for (int y = 0; y < n; y++)
        {
            for (int x = 0; x < m; x++)
            {
                if (storage[y][x] != letter)
                {
                    continue;
                }
                
                bool accessible = false;

                if (y == 0 || y == n - 1 
                    || x == 0 || x == m - 1) 
                {
                    accessible = true;
                } 
                else 
                {
                    for (int k = 0; k < 4; k++)
                    {
                        int nextY = y + moveDir[k].y;
                        int nextX = x + moveDir[k].x;
                        
                        if (nextY < 0 || nextY >= n 
                            || nextX < 0 || nextX >= m) 
                        {
                            accessible = true;
                            
                            break;
                        }
                        
                        if (storage[nextY][nextX] == '.' && reachable[nextY][nextX])
                        {
                            accessible = true;
                            
                            break;
                        }
                    }
                }

                if (accessible) 
                {
                    storage[y][x] = '.';
                }
            }
        }
    }
    
    int answer = 0;
    
    for (int y = 0; y < n; y++)
    {
        for (int x = 0; x < m; x++)
        {
            if (storage[y][x] != '.')
            {
                answer++;
            }
        }
    }
    
    return answer;
}
