#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> players, int m, int k) {
    int answer = 0;
    queue<int> q;
    
    for (int t = 0; t < 24; t++) 
    {
        while (!q.empty() && q.front() <= t) 
        {
            q.pop();
        }
        
        int required = players[t] / m;
        
        if (required > q.size())
        {
            int expansion = required - q.size();
            answer += expansion;
            
            for (int i = 0; i < expansion; i++) 
            {
                q.push(t + k);
            }
        }
    }
    
    return answer;
}
