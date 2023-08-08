#include <string>
#include <vector>
#include <map>
using namespace std;

map<char, bool> visited;

string solution(string my_string) {
    string answer = "";
    
    for (char c : my_string)
    {
        if (visited[c])
        {
            continue;
        }
        
        visited[c] = true;
        answer += c;
    }
    
    return answer;
}
