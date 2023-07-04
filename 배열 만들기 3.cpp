#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr, vector<vector<int>> intervals) {
    vector<int> answer;
    
    for (vector<int> interval : intervals)
    {
        for (int i = interval[0]; i <= interval[1]; i++)
        {
            answer.push_back(arr[i]);
        }
    }
    
    return answer;
}