#include <string>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 1e5 + 1;

bool visited[MAX];

int solution(int n, int m, vector<int> section) {
    int answer = 0;
    
    for (int s : section)
    {
        if (visited[s])
        {
            continue;
        }
        
        for (int i = s; i < min(s + m, n + 1); i++)
        {
            visited[i] = true;
        }
        
        answer++;
    }
    
    return answer;
}
