#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

const int MAX = 100;

typedef struct
{
    int y, x;
    int cnt;
} State;

bool operator<(const State a, const State b)
{
    return a.cnt > b.cnt;
}

typedef struct
{
    int y, x;
} Dir;

Dir moveDir[4] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

int N, M;
bool visited[MAX][MAX][4];

bool isOutOfBounds(int y, int x)
{
    return y < 0 || y >= N || x < 0 || x >= M;
}

int solution(vector<string> board) {
    priority_queue<State> pq;
    N = board.size();
    M = board[0].size();
    
    for (int y = 0; y < N; y++)
    {
        for (int x = 0; x < M; x++)
        {
            if (board[y][x] == 'R')
            {
                pq.push({y, x, 0});
                
                for (int k = 0; k < 4; k++)
                {
                    visited[y][x][k] = true;
                }

                break;
            }
        }
        
        if (!pq.empty())
        {
            break;
        }
    }
    
    while (!pq.empty())
    {
        State s = pq.top();
        int y = s.y;
        int x = s.x;
        int cnt = s.cnt;
        pq.pop();
        
        if (board[y][x] == 'G')
        {
            return cnt;
        }
        
        for (int k = 0; k < 4; k++)
        {
            int tempY = y;
            int tempX = x;
            bool flag = false;
            
            while (true)
            {
                int nextY = tempY + moveDir[k].y;
                int nextX = tempX + moveDir[k].x;
                
                if (isOutOfBounds(nextY, nextX))
                {
                    break;
                }
                
                if (board[nextY][nextX] == 'D')
                {
                    break;
                }
                
                if (visited[nextY][nextX][k])
                {
                    flag = true;
                    
                    break;
                }
                
                visited[nextY][nextX][k] = true;
                tempY = nextY;
                tempX = nextX;
            }
            
            if (flag)
            {
                continue;
            }
            
            if (!(tempY == y && tempX == x))
            {
                pq.push({tempY, tempX, cnt + 1});
            }
        }   
    }
    
    return -1;
}
