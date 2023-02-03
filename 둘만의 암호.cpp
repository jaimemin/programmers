#include <string>
#include <vector>
#include <set>
using namespace std;

string solution(string s, string skip, int index) {
    string answer = s;
    set<char> skipSet;
    
    for (char c : skip)
    {
        skipSet.insert(c);
    }
    
    for (int i = 0; i < answer.size(); i++)
    {
        int cnt = index;
        
        while (cnt)
        {
            answer[i] = answer[i] == 'z' ? 'a' : answer[i] + 1;
            
            if (skipSet.find(answer[i]) != skipSet.end())
            {
                continue;
            }
            
            cnt--;
        }
    }
    
    return answer;
}
