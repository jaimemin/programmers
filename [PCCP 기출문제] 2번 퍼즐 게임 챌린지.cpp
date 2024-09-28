#include <vector>
#include <algorithm>
using namespace std;

long long computeTotalTime(vector<int>& diffs, vector<int>& times, int level) 
{
    int n = diffs.size();
    long long totalTime = 0;

    for (int i = 0; i < n; i++) 
    {
        if (diffs[i] <= level) 
        {
            totalTime += times[i];
        } 
        else 
        {
            int mistakes = diffs[i] - level;
            
            if (i == 0) 
            {
                totalTime += times[i] * (mistakes + 1);
            } 
            else 
            {
                int timePrev = times[i - 1];
                
                totalTime += (times[i] * 1LL + timePrev) * mistakes + times[i];
            }
        }
    }

    return totalTime;
}

int solution(vector<int> diffs, vector<int> times, long long limit) 
{
    int n = diffs.size();
    int left = 1;
    int right = 100001;

    while (left < right) 
    {
        int mid = (left + right) / 2;
        long long totalTime = computeTotalTime(diffs, times, mid);

        if (totalTime <= limit) 
        {
            right = mid;
        } 
        else 
        {
            left = mid + 1;
        }
    }

    return left;
}
