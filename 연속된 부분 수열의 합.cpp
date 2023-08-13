#include <string>
#include <vector>

using namespace std;

const int INF = 987654321;

vector<int> solution(vector<int> sequence, int k) {
    int start = 0;
    int end = 0;
    int sum = sequence[end];
    int subArrLen = INF;
    vector<int> answer(2, 0);
    
    while (start <= end && end < sequence.size())
    {
        if (sum < k)
        {
            sum += sequence[++end];
            
            continue;
        }
        
        if (sum == k)
        {
            int len = end - start + 1;
            
            if (subArrLen > len)
            {
                subArrLen = len;
                answer[0] = start;
                answer[1] = end;
            }
            else if (subArrLen == len)
            {
                if (answer[0] > start)
                {
                    answer[0] = start;
                    answer[1] = end;
                }
            }
        }
        
        sum -= sequence[start++];
    }
    
    return answer;
}
