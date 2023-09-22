#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

bool cmp(pair<double, int> a, pair<double, int> b)
{
    if (a.first > b.first)
    {
        return true;
    }
    
    return false;
}

vector<int> solution(vector<vector<int>> score) {
    vector<int> answer(score.size());
    vector<pair<double, int>> v;
    int idx = 0;
    
    for (vector<int> s : score)
    {
        double avg = ((double) s[0] + (double) s[1]) / 2;
        
        v.push_back({avg, idx++});    
    }
    
    sort(v.begin(), v.end(), cmp);
    
    int rank = 1;
    int cnt = 1;
    answer[v[0].second] = rank;
    double prev = v[0].first;
    
    for (int i = 1; i < v.size(); i++)
    {
        cout << prev << " " << v[i].first << "\n";
        if (prev != v[i].first)
        {
            rank += cnt;
            cnt = 1;
        }
        else
        {
            cnt++;
        }
        
        answer[v[i].second] = rank;
        prev = v[i].first;
    }
    
    return answer;
}
