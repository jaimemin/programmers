#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer;
    
    for (int num : arr)
    {
        for (int i = 0; i < num; i++)
        {
            answer.push_back(num);
        }
    }
    
    return answer;
}