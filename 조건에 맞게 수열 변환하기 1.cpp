#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer;
    
    for (int num : arr)
    {
        if (num >= 50 && num % 2 == 0)
        {
            answer.push_back(num / 2);
        }
        else if (num < 50 && num % 2)
        {
            answer.push_back(num * 2);
        }
        else
        {
            answer.push_back(num);
        }
    }
    
    return answer;
}