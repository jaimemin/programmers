#include <string>
#include <vector>

using namespace std;

int solution(int i, int j, int k) {
    int answer = 0;
    
    for (int a = i; a <= j; a++)
    {
        int num = a;
        
        while (num)
        {
            if (num % 10 == k)
            {
                answer++;
            }
            
            num /= 10;
        }
    }
    
    return answer;
}
