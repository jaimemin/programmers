#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr, vector<bool> flag) {
    vector<int> answer;
    
    for (int i = 0; i < flag.size(); i++)
    {
        bool f = flag[i];
        int num = arr[i];
        
        for (int j = 0; j < (f ? num * 2 : num); j++)
        {
            if (f)
            {
                answer.push_back(num);
            }
            else
            {
                answer.pop_back();
            }
        }
    }
    
    return answer;
}