#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> array, int n) {
    int answer = array[0];
    
    for (int num : array)
    {
        int diff = abs(answer - n);
        int diff2 = abs(num - n);
        
        if (diff > diff2)
        {
            answer = num;
        }
        else if (diff == diff2)
        {
            answer = min(answer, num);
        }
    }
    
    return answer;
}
