#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int standard;

bool cmp(int a, int b)
{
    int aDiff = abs(a - standard);
    int bDiff = abs(b - standard);
    
    if (aDiff < bDiff)
    {
        return true;
    }
    
    if (aDiff == bDiff)
    {
        return a > b;
    }
    
    return false;
}

vector<int> solution(vector<int> numlist, int n) {
    standard = n;
    
    sort(numlist.begin(), numlist.end(), cmp);
    
    return numlist;
}
