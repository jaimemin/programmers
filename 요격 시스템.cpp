#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(vector<int> &a, vector<int> &b) {
    return a[1] < b[1];
}

int solution(vector<vector<int>> targets) {
    int answer = 0;
    int prevEnd = -1;
    
    sort(targets.begin(), targets.end(), cmp);
    
    for (vector<int> target : targets) {
        int start = target[0];
        int end = target[1];
        
        if (start < prevEnd && end >= prevEnd)
        {
            continue;
        }
        else 
        {
            prevEnd = end;
            
            answer++;
        }
    }
    
    return answer;
}
