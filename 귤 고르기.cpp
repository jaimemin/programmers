#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

int solution(int k, vector<int> tangerine) {
    int answer = 0;
    set<int> visited;
    map<int, int> type2cnt;
    
    for (int t : tangerine)
    {
        visited.insert(t);
        type2cnt[t]++;
    }
    
    vector<pair<int, int>> v;
    
    for (int type : visited)
    {
        v.push_back({type2cnt[type], type});
    }
    
    sort(v.begin(), v.end());
    
    for (int i = v.size() - 1; i >= 0; i--)
    {
        answer++;
        
        k -= v[i].first;
        
        if (k <= 0)
        {
            break;
        }
    }
    
    return answer;
}
