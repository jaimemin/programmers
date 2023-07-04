#include <string>
#include <vector>
using namespace std;

int getCnt(int num)
{
    if (num == 1)
    {
        return 0;
    }
    
    int cnt = 1;
    
    for ( ; num != 1; cnt++)
    {
        if (num % 2)
        {
            num = (num - 1) / 2;
        }
        else
        {
            num /= 2;
        }
    }
    
    return cnt - 1;
}

int solution(vector<int> num_list) {
    int answer = 0;
    
    for (int num : num_list)
    {
        answer += getCnt(num);
    }
    
    return answer;
}