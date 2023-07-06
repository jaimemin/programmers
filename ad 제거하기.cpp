#include <string>
#include <vector>

using namespace std;

vector<string> solution(vector<string> strArr) {
    vector<string> answer;
    
    for (string s : strArr)
    {
        if (s.find("ad") != string::npos)
        {
            continue;
        }
        
        answer.push_back(s);
    }
    
    return answer;
}