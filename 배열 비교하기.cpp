#include <string>
#include <vector>

using namespace std;

int getSum(vector<int> &v)
{
    int sum = 0;
    
    for (int num : v)
    {
        sum += num;
    }
    
    return sum;
}

int solution(vector<int> arr1, vector<int> arr2) {
    if (arr1.size() > arr2.size())
    {
        return 1;
    }
    else if (arr1.size() < arr2.size())
    {
        return -1;
    }
    else
    {
        int sum = getSum(arr1), sum2 = getSum(arr2);
        
        if (sum > sum2)
        {
            return 1;
        }
        else if (sum < sum2)
        {
            return -1;
        }
        else
        {
            return 0;
        }
    }
}