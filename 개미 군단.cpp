#include <string>
#include <vector>

using namespace std;

int solution(int hp) {
    int answer = 0;
    
    for (int atk = 5; atk >= 1; atk -= 2)
    {
        while (hp - atk >= 0)
        {
            answer++;
            
            hp -=atk;
        }
    }
    
    return answer;
}
