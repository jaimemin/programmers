#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string solution(string myString, string pat) {
    reverse(myString.begin(), myString.end());
    reverse(pat.begin(), pat.end());
    string answer = "";
    
    for (int i = 0; i < myString.length(); i++)
    {
        if (myString.substr(i, pat.length()) == pat)
        {
            answer = myString.substr(i);
            
            break;
        }
    }
    
    reverse(answer.begin(), answer.end());
    
    return answer;
}