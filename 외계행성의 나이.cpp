#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string solution(int age) {
    string answer = "";
    
    while (age)
    {
        int mod = age % 10;
        answer += (mod + 'a');
        
        age /= 10;
    }
    
    reverse(answer.begin(), answer.end());
    
    return answer;
}
