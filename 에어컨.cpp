#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

const int INF = 987654321;

const int MAX = 1e3 + 10;

const int TEMPERATURE_RANGE = 50;

int cache[MAX][TEMPERATURE_RANGE + 1];

int solution(int temperature, int t1, int t2, int a, int b, vector<int> onboard) {
    if (temperature >= t1 && t2 >= temperature)
    {
        return 0;
    }
    
    temperature += 10;
    t1 += 10;
    t2 += 10;
    
    for (int i = 0; i < MAX; i++)
    {
        for (int j = 0; j <= TEMPERATURE_RANGE; j++)
        {
            cache[i][j] = INF;
        }
    }
    
    cache[0][temperature] = 0;
    
    for (int i = 0; i < onboard.size() - 1; i++)
    {
        for (int j = 0; j <= TEMPERATURE_RANGE; j++)
        {
            // 기저 사례: 손님이 탑승했을 때는 온도 조건을 충족해야 함
            if (onboard[i] && 
               (t1 > j || j > t2))
            {
                continue;
            }
            
            int nextTemperature = j;
            
            if (j < temperature && j < TEMPERATURE_RANGE)
            {
                nextTemperature++;
            }
            else if (j > temperature && j > 0)
            {
                nextTemperature--;
            }
            
            // 에어컨 껐을 때
            cache[i + 1][nextTemperature] = min(cache[i + 1][nextTemperature], cache[i][j]);
            
            // 에어컨을 켰고 온도 변화가 있을 때
            if (j > 0)
            {
                cache[i + 1][j - 1] = min(cache[i + 1][j - 1], a + cache[i][j]);
            }
            
            if (j < TEMPERATURE_RANGE)
            {
                cache[i + 1][j + 1] = min(cache[i + 1][j + 1], a + cache[i][j]);
            }
            // 에어컨을 켰고 온도 변화가 있을 때
            
            // 에어컨을 켰고 온도 유지 중일 때
            cache[i + 1][j] = min(cache[i + 1][j], b + cache[i][j]);
        }
    }
    
    int result = INF;
    int len = onboard.size();

    for (int j = 0; j <= TEMPERATURE_RANGE; j++)
    {
        if (onboard[len - 1] == 1 
            && (t1 > j || j > t2))
        {
            continue;
        }
        
        result = min(result, cache[len - 1][j]);
    }
    
    return result;
}
