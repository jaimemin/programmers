#include <string>
#include <vector>
#include <set>
using namespace std;

int solution(int x, int y, int n) {
    int answer = 0;
    set<int> s;
    s.insert(x);
    
    while (!s.empty())
    {
        if (s.find(y) != s.end())
        {
            return answer;
        }
        
        set<int> s2;
        
        for (int num : s)
        {
            if (num + n <= y)
            {
                s2.insert(num + n);
            }
            
            if (num * 2 <= y)
            {
                s2.insert(num * 2);
            }
            
            if (num * 3 <= y)
            {
                s2.insert(num * 3);
            }
        }
        
        s = s2;
        answer++;
    }
    
    return -1;
}
