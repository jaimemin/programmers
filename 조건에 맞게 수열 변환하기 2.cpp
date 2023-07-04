#include <string>
#include <vector>
using namespace std;

vector<int> copy(vector<int> &arr)
{
    vector<int> temp;
    
    for (int num : arr)
    {
        temp.push_back(num);
    }
    
    return temp;
}

bool isSame(vector<int> &a, vector<int> &b)
{
    if (a.size() != b.size())
    {
        return false;
    }
    
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] != b[i])
        {
            return false;
        }
    }
    
    return true;
}

int solution(vector<int> arr) {
    
    for (int i = 0; ; i++)
    {
        vector<int> nextArr;

        for (int num : arr)
        {
            if (num >= 50 && num % 2 == 0)
            {
                nextArr.push_back(num / 2);
            }
            else if (num < 50 && num % 2)
            {
                nextArr.push_back(num * 2 + 1);
            }
            else
            {
                nextArr.push_back(num);
            }
        }
        
        if (isSame(arr, nextArr))
        {
            return i;
        }
        
        arr = copy(nextArr);
    }
}