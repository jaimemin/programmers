#include <vector>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <climits>
using namespace std;

const int MAX = 50;

typedef struct
{
    int y, x;
} Dir;

Dir moveDir[4] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

long long dp[MAX][MAX][MAX * MAX + MAX];

vector<vector<int>> map;

int M, N, S;

long long solve(int y, int x, int dist)
{
    long long &result = dp[y][x][dist];
    
    if (y == M - 1 
        && x == N - 1 
        && dist == 0) 
    {
        return result = 0;
    }
    
    if (result != -1)
    {
        return result;
    }
    
    result = INT_MAX;
    
    for (int k = 0; k < 4; k++)
    {
        
        int nextY = y + moveDir[k].y;
        int nextX = x + moveDir[k].x;
        
        if (nextY < 0 || nextY >= M || nextX < 0 || nextX >= N)
        {
            continue;
        }
        
        if (map[nextY][nextX] == -1 || dist < 1)
        {
            continue;
        }
        
        long long candidate = solve(nextY, nextX, dist - 1) + map[y][x];
        
        if (candidate <= S)
        {
            result = min(result, candidate);
        }
    }
    
    return result;
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, int s, vector<vector<int>> time_map) {
    memset(dp, -1, sizeof(dp));
    map = time_map;
    M = m; 
    N = n; 
    S = s;
    
    int moveDistance = INT_MAX;
    int sumOfTalkTime = INT_MAX;
    
    for (int i = M + N - 2; i <= M * N; i++)
    {
        long long result = solve(0, 0, i); 

        if (result < INT_MAX)
        {
            moveDistance = i;
            sumOfTalkTime = result;
            
            break;
        }
    }
    
    return {moveDistance, sumOfTalkTime};
}
