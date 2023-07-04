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

vector<int> solution(vector<int> arr, vector<int> query) {
    for (int i = 0; i < query.size(); i++)
    {
        int q = query[i];
        vector<int> temp;
        
        if (i % 2)
        {
            for (int i = q; i < arr.size(); i++)
            {
                temp.push_back(arr[i]);
            }
        }
        else 
        {
            for (int i = 0; i <= q; i++)
            {
                temp.push_back(arr[i]);
            }
        }
        
        arr = copy(temp);
    }
    
    return arr;
}