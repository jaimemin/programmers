#include <string>
#include <vector>

using namespace std;

string solution(string rsp) {
    string answer = "";
    
    for (char r : rsp)
    {
        switch (r)
        {
            case '0':
                answer += "5";
                
                break;
            case '2':
                answer += "0";
                
                break;
            case '5':
                answer += "2";
                
                break;
        }
    }
    
    return answer;
}
