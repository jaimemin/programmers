#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer;
    
    for (int i = 0; i < arr.size(); )
    {
        if (answer.empty())
        {
            answer.push_back(arr[i++]);
        }
        else
        {
            if (answer.back() == arr[i])
            {
                answer.pop_back();
                i++;
            }
            else
            {
                answer.push_back(arr[i++]);
            }
        }
    }
    
    if (answer.empty())
    {
        answer.push_back(-1);
    }
    
    return answer;
}