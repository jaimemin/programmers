#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int solution(vector<int> rank, vector<bool> attendance) {
    vector<pair<int, int>> v;
    
    for (int i = 0; i < rank.size(); i++)
    {
        if (!attendance[i])
        {
            continue;
        }
        
        v.push_back({rank[i], i});
    }
    
    sort(v.begin(), v.end());
    
    int answer = 0;
    
    for (int i = 0; i < 3; i++)
    {
        answer += v[i].second * (int) pow(10, 4 - i * 2);
    }
    
    return answer;
}