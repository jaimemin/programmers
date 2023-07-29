#include <iostream>
#include <string>
#include <vector>
#include <set>
using namespace std;

int solution(vector<string> spell, vector<string> dic) {
    for (string d : dic)
    {
        set<char> visited;
        
        for (string s : spell)
        {
            char *c = s.data();
            visited.insert(c[0]);
        }
        
        for (char c : d)
        {
            if (visited.find(c) == visited.end())
            {
                break;
            }
            
            visited.erase(c);
        }
        
        if (visited.empty())
        {
            return 1;
        }
    }
    
    return 2;
}
