#include <string>
#include <vector>
using namespace std;

const int MAX = 1e4;

bool visited[MAX];

vector<int> solution(int n) {
    vector<int> answer;
    
    for (int i = 2; n != 1; i++)
    {
        while (n % i == 0)
        {
            if (!visited[i])
            {
                answer.push_back(i);
            }
            
            visited[i] = true;
            n /= i;
        }
    }
    
    return answer;
}
