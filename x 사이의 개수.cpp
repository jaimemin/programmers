#include <string>
#include <vector>

using namespace std;

vector<int> solution(string myString) {
    vector<int> answer;
    string temp = "";
    
    for (char c : myString)
    {
        if (c == 'x')
        {
            answer.push_back(temp.length());
            temp = "";
            
            continue;
        }
        
        temp += c;
    }
    
    answer.push_back(temp.length());
    
    return answer;
}