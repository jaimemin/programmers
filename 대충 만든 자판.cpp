#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

vector<int> solution(vector<string> keymap, vector<string> targets) {
    map<char, int> char2cnt;
    
    for (string key : keymap)
    {
        for (int i = 0; i < key.size(); i++)
        {
            char c = key[i];
            
            char2cnt[c] = char2cnt[c] == 0 ? i + 1 : min(char2cnt[c], i + 1);
        }
    }
    
    vector<int> answer;
    
    for (string target : targets)
    {
        int cnt = 0;
        bool flag = true;
        
        for (char c : target)
        {
            if (char2cnt[c] == 0)
            {
                flag = false;
                answer.push_back(-1);
                
                break;
            }
            
            cnt += char2cnt[c];    
        }
        
        if (flag)
        {
            answer.push_back(cnt);
        }
    }
    
    return answer;
}
