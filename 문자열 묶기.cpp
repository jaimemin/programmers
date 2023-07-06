#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

int solution(vector<string> strArr) {
    map<int, vector<string>> cnt2vector;
    set<int> cnts;
    
    for (string s : strArr)
    {
        cnts.insert(s.length());
        cnt2vector[s.length()].push_back(s);
    }
    
    int answer = 0;
    
    for (int cnt : cnts)
    {
        answer = max(answer, (int) cnt2vector[cnt].size());
    }
    
    return answer;
}