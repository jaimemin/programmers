#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <iostream>
using namespace std;

int solution(vector<vector<int>> scores) {
    int target = scores[0][0] + scores[0][1];
    vector<int> v;
    v.push_back(target);
    map<int, int> score2cnt;
    score2cnt[target]++;
    
    
    for (int i = 1; i < scores.size(); i++)
    {
        if (scores[i][0] > scores[0][0] 
            && scores[i][1] > scores[0][1])
        {
            return -1;
        }
        
        int sum = scores[i][0] + scores[i][1];
        
        if (!score2cnt.count(sum))
        {
            v.push_back(sum);
        }
        
        score2cnt[sum]++;
    }
    
    sort(v.begin(), v.end());
    
    if (v.back() == target)
    {
        return 1;
    }
    
    int answer = 1;
    
    for (int i = v.size() - 1; i >= 0; i--)
    {
        if (v[i] == target)
        {
            return answer;
        }
        
        answer += score2cnt[v[i]];
    }
}
