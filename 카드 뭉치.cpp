#include <string>
#include <vector>
#include <map>
using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
    int idx = 0, idx2 = 0;
    
    for (string s : goal)
    {
        if (s == cards1[idx])
        {
            idx = (idx < cards1.size() - 1) ? idx + 1 : idx;
        }
        else if (s == cards2[idx2])
        {
            idx2 = (idx2 < cards2.size() - 1) ? idx2 + 1 : idx2;
        }
        else
        {
            return "No";
        }
    }
    
    
    return "Yes";
}
