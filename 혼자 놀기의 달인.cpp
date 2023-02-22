#include <string>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 100;

bool visited[MAX];

int solution(vector<int> cards) {
    vector<int> boxCnts;
    
    for (int i = 0; i < cards.size(); i++)
    {
        int cnt = 0;
        int idx = i;
        
        while (1)
        {
            if (visited[idx])
            {
                if (cnt)
                {
                    boxCnts.push_back(cnt);
                }
                
                break;
            }
            
            cnt++;
            visited[idx] = true;
            idx = cards[idx] - 1;
        }
    }
    
    if (boxCnts.size() <= 1)
    {
        return 0;
    }
    
    int size = boxCnts.size();
    sort(boxCnts.begin(), boxCnts.end());
    
    return boxCnts[size - 1] * boxCnts[size - 2];
}
