#include <string>
#include <vector>
#include <iostream>
using namespace std;

const int INF = 987654321;

bool isEqual(vector<vector<int>> &beginning, vector<vector<int>> &target)
{
    int ySize = beginning.size();
    int xSize = beginning[0].size();
    
    for (int y = 0; y < ySize; y++)
    {
        for (int x = 0; x < xSize; x++)
        {
            if (beginning[y][x] != target[y][x])
            {
                return false;
            }
        }
    }
    
    return true;
}

int simulate(vector<vector<int>> beginning, vector<vector<int>> &target, int bit)
{
    int cnt = 0;
    int ySize = beginning.size();
    int xSize = beginning[0].size();
    
    for (int y = 0; y < ySize; y++)
    {
        if (bit & (1 << y))
        {
            cnt++;
            
            for (int x = 0; x < xSize; x++)
            {
                beginning[y][x] = 1 - beginning[y][x];
            }
        }
    }
    
    for (int x = 0; x < xSize; x++)
    {
        if (bit & (1 << (ySize + x)))
        {
            cnt++;
            
            for (int y = 0; y < ySize; y++)
            {
                beginning[y][x] = 1 - beginning[y][x];
            }
        }
    }
    
    if (isEqual(beginning, target))
    {
        return cnt;
    }
    
    return INF;
}

int solution(vector<vector<int>> beginning, vector<vector<int>> target) {
    int answer = INF;
    int ySize = beginning.size();
    int xSize = beginning[0].size();
    
    for (int bit = 0; bit < 1 << (ySize + xSize); bit++)
    {
        answer = min(answer, simulate(beginning, target, bit));
    }
    
    return answer == INF ? -1 : answer;
}
