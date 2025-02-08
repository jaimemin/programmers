#include <iostream>
#include <vector>
#include <map>

using namespace std;

const int MOD = 1000000007;

// “레벨 i”에서 각 셀(cell)의 값(merge 후 합)과 
// 그 값이 처음 등장한 이전 인덱스를 기록하는 map
vector<map<long long, int>> levelMaps;

// dp[i]는 “레벨 i”까지 진행했을 때 해당 상태에 도달할 수 있는 경우의 수
vector<long long> dp;

long long connect(long long cellValue, int currentIndex, int prevIndex) 
{
    // 현재 레벨에 cellValue가 기록되어 있지 않다면, (cellValue, prevIndex) 쌍을 등록
    if (levelMaps[currentIndex].find(cellValue) == levelMaps[currentIndex].end())
    {
        levelMaps[currentIndex][cellValue] = prevIndex;
    }
    
    // 우선 부모 셀(prevIndex)까지의 경우의 수로 초기화
    long long ways = dp[prevIndex];
    
    // 만약 바로 이전 레벨(prevIndex)에서 동일한 cellValue가 있었다면,
    // merge가 가능하므로, 해당 셀과 merge하여 cellValue가 2배가 된 경우의 수를 추가
    if (levelMaps[prevIndex].find(cellValue) != levelMaps[prevIndex].end()) 
    {
        int mergeOrigin = levelMaps[prevIndex][cellValue];
        
        ways = (ways + connect(cellValue * 2, currentIndex, mergeOrigin)) % MOD;
    }
    
    return ways;
}


vector<int> solution(vector<int> a, vector<int> s) 
{
    vector<int> answer;
    int totalSize = a.size() + 1;
    
    levelMaps.assign(totalSize, map<long long, int>());
    dp.assign(totalSize, 0);
    
    int segmentStart = 0;
    int segmentEnd = 0;
    
    for (int seg = 0; seg < s.size(); seg++) 
    {
        int segmentLength = s[seg];
        segmentStart = segmentEnd;
        segmentEnd = segmentStart + segmentLength;
        
        levelMaps[segmentStart].clear();
        levelMaps[segmentStart][-1] = -1;
        dp[segmentStart] = 1;

        for (int i = segmentStart + 1; i <= segmentEnd; i++) 
        {
            dp[i] = connect(a[i - 1], i, i - 1);
        }
        
        answer.push_back((int)(dp[segmentEnd] % MOD));
    }
    
    return answer;
}
