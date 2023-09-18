#include <string>
#include <vector>

using namespace std;

int arr[26] = {0,};

int solution(string before, string after) {
    for (char c : before)
    {
        arr[c - 'a']++;
    }
    
    for (char c : after)
    {
        if (--arr[c - 'a'] < 0)
        {
            return 0;
        }
    }
    
    return 1;
}
