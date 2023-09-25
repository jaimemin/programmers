#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

map<int, int> m;

int solution(vector<vector<int>> lines) {
    int answer = 0;
    
    for(vector<int> line : lines) 
    {
        for(int i = line[0]; i < line[1]; i++) 
        {
            m[i]++;
        }
    }
    
    for (const auto &i : m) 
    {
        answer += i.second >= 2;
    }
    
    return answer;
}
