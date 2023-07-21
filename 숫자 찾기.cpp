#include <string>
#include <vector>

using namespace std;

int solution(int num, int k) {
    string numStr = to_string(num);
    
    for (int i = 0; i < numStr.length(); i++)
    {
        if ((numStr[i] - '0') == k)
        {
            return i + 1;
        }
    }
    
    return -1;
}
