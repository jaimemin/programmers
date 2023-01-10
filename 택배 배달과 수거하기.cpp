#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> getFarthestForEachTurn(vector<int> &v, int cap)
{
    vector<int> farthest;
    int capacity = cap;
    int farthestIdx = -1;
    
    for (int i = v.size() - 1; i >= 0; )
    {
        if (v[i] == 0)
        {
            i--;
            
            continue;
        }
        
        int diff = min(capacity, v[i]);
        capacity -= diff;
        v[i] -= diff;
        farthestIdx = (farthestIdx == -1 ? i : farthestIdx);
        
        if (capacity == 0)
        {
            farthest.push_back(farthestIdx + 1);
            capacity = cap;
            farthestIdx = -1;
        }
    }
    
    if (farthestIdx != -1)
    {
        farthest.push_back(farthestIdx + 1);
    }
    
    return farthest;
}

long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups)
{
    long long answer = 0;
    vector<int> deliveriesFarthest = getFarthestForEachTurn(deliveries, cap);
    vector<int> pickupsFarthest = getFarthestForEachTurn(pickups, cap);

    for (int i = 0, j = 0; i < deliveriesFarthest.size() || j < pickupsFarthest.size(); i++, j++)
    {
        int deliveryMaxLen = i < deliveriesFarthest.size() 
            ? deliveriesFarthest[i] : 0;
        int pickupMaxLen = j < pickupsFarthest.size() 
            ? pickupsFarthest[j] : 0;
        
        answer += max(deliveryMaxLen, pickupMaxLen) * 2;
    }
    
    return answer;
}
