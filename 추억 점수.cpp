#include <string>
#include <vector>
#include <map>
using namespace std;

vector<int> solution(vector<string> name, vector<int> yearning, vector<vector<string>> photo) {
    map<string, int> name2yearning;
    
    for (int i = 0; i < name.size(); i++)
    {
        name2yearning[name[i]] = yearning[i];
    }
    
    vector<int> answer;
    
    for (vector<string> p : photo)
    {
        int total = 0;
        
        for (string s : p)
        {
            total += name2yearning[s];    
        }
        
        answer.push_back(total);
    }
    
    return answer;
}
