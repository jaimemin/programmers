#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

const int INF = 987654321;

const int MAX = 4;

const int RED = 0;

const int BLUE = 1;

const int RED_GOAL = 3;

const int BLUE_GOAL = 4;

const int WALL = 5;

typedef struct
{
    int y, x;
} Dir;

Dir moveDir[5] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}, {0, 0}};

int answer = INF;
int N, M;
pair<int, int> red, blue;

bool visited[MAX][MAX][2];

bool isOutOfBounds(int y, int x)
{
    return y < 0 || y >= N || x < 0 || x >= M;
}

bool collapsed(int y, int x, int y2, int x2)
{
    return y == y2 && x == x2;
}

bool overlapped(pair<int, int> redPos, pair<int, int> nextRedPos, pair<int, int> bluePos, pair<int, int> nextBluePos)
{
    return redPos == nextBluePos && bluePos == nextRedPos;
}

bool bothArrivedAtGoals(pair<int, int> redPos, pair<int, int> bluePos, vector<vector<int>> &maze)
{
    return maze[redPos.first][redPos.second] == RED_GOAL
        && maze[bluePos.first][bluePos.second] == BLUE_GOAL;
}

void func(pair<int, int> redPos, pair<int, int> bluePos, int cnt, vector<vector<int>> &maze)
{
    if (bothArrivedAtGoals(redPos, bluePos, maze))
    {
        answer = min(answer, cnt);
        
        return;
    }
    
    for (int k = 0; k < 5; k++)
    {
        int nextRedY = redPos.first + moveDir[k].y;
        int nextRedX = redPos.second + moveDir[k].x;
        
        if (isOutOfBounds(nextRedY, nextRedX)
            || (maze[nextRedY][nextRedX] != RED_GOAL && visited[nextRedY][nextRedX][RED])
            || maze[nextRedY][nextRedX] == WALL)
        {
            continue;
        }
        
        visited[nextRedY][nextRedX][RED] = true;
        
        for (int l = 0; l < 5; l++)
        {
            if (k == 4 && l == 4)
            {
                break;
            }
            
            int nextBlueY = bluePos.first + moveDir[l].y;
            int nextBlueX = bluePos.second + moveDir[l].x;

            if (isOutOfBounds(nextBlueY, nextBlueX)
                || (maze[nextBlueY][nextBlueX] != BLUE_GOAL && visited[nextBlueY][nextBlueX][BLUE])
                || maze[nextBlueY][nextBlueX] == WALL 
                || collapsed(nextRedY, nextRedX, nextBlueY, nextBlueX)
                || overlapped(redPos, {nextRedY, nextRedX}, bluePos, {nextBlueY, nextBlueX}))
            {
                continue;
            }
            
            visited[nextBlueY][nextBlueX][BLUE] = true;
            func({nextRedY, nextRedX}, {nextBlueY, nextBlueX}, cnt + 1, maze);
            visited[nextBlueY][nextBlueX][BLUE] = false;
        }
        
        visited[nextRedY][nextRedX][RED] = false;
    }
}

int solution(vector<vector<int>> maze) {
    N = maze.size();
    M = maze[0].size();
    
    for (int y = 0; y < N; y++)
    {
        for (int x = 0; x < M; x++)
        {
            switch (maze[y][x])
            {
                case 1:
                    red = {y, x};
                    visited[y][x][RED] = true;
                    
                    break;
                case 2:
                    blue = {y, x};
                    visited[y][x][BLUE] = true;
                    
                    break;
            }
        }
    }
    
    func(red, blue, 0, maze);
    
    return answer == INF ? 0 : answer;
}
