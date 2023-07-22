#include <string>
#include <vector>

using namespace std;

int solution(int order) {
    int answer = 0;
    
    while (order)
    {
        if (order % 10 == 0)
        {
            order /= 10;
            
            continue;
        }
        
        answer += (order % 10) % 3 == 0;
        
        order /= 10;
    }
    
    return answer;
}
