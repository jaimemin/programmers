#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> sides) {
    int answer = 0;
    
    for (int len = 1; len < 2000; len++)
    {
        vector<int> v(3);
        
        for (int i = 0; i < 2; i++)
        {
            v[i] = sides[i];
        }
        
        v[2] = len;
        sort(v.begin(), v.end());
        
        if (v[0] + v[1] > v[2])
        {
            answer++;
        }
    }
    
    return answer;
}
