#include <string>
#include <vector>

using namespace std;

int solution(string my_string) {
    int answer = 0;
    string temp = "";
    
    for (char c : my_string)
    {
        if (!(c >= '0' && c <= '9'))
        {
            answer += (temp == "" ? 0 : stoi(temp));
            temp = "";
            
            continue;
        }
        
        temp += c;
    }
    
    answer += (temp == "" ? 0 : stoi(temp));
    
    return answer;
}
