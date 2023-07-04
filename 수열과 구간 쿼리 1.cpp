#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr, vector<vector<int>> queries) {
    for (vector<int> query : queries)
    {
        for (int i = query[0]; i <= query[1]; i++)
        {
            arr[i]++;
        }
    }
    
    return arr;
}