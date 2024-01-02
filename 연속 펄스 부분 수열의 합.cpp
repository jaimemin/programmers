#include <string>
#include <vector>
#include <climits>
using namespace std;

const int MAX = 1e5 * 5 + 1;

long long getMaxSubSequenceSum(vector<int> &sequence, int start)
{
    vector<long long> v;
    long long cache[MAX] = {0, };
    
    for (int seq : sequence)
    {
        v.push_back(seq * start * 1LL);
        
        start *= -1;
    }
    
    long long answer = LLONG_MIN;
    cache[0] = v[0];
    
    for (int i = 1; i < v.size(); i++)
    {
        cache[i] = max(v[i], cache[i - 1] + v[i]);
        
        answer = max(answer, cache[i]);
    }
    
    return answer;
}

long long solution(vector<int> sequence) {
    if (sequence.size() == 1)
    {
        return max(sequence[0], sequence[0] * -1);    
    }
    
    return max(getMaxSubSequenceSum(sequence, 1), getMaxSubSequenceSum(sequence, -1));
}
