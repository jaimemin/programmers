#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
using namespace std;

set<int> nums;
map<int, int> num2cnt;

bool cmp(pair<int, int> a, pair<int, int> b)
{
    return a.first > b.first;
}

int solution(vector<int> array) {
    for (int num : array)
    {
        num2cnt[num]++;
        nums.insert(num);
    }
    
    vector<pair<int, int>> v;
    
    for (int num : nums)
    {
        v.push_back({num2cnt[num], num});
    }
    
    sort(v.begin(), v.end(), cmp);
    
    int answer = v[0].second;
    
    if (v[0].first == v[1].first)
    {
        return -1;
    }
    
    return answer;
}
