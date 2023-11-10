#include <string>
#include <vector>

using namespace std;

int solution(string my_string) {
    int answer = 0;
    
    for (char c : my_string)
    {
        answer += (c >= '0' && c <= '9') ? c - '0' : 0;
    }
    
    return answer;
}
