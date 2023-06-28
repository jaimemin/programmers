#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr, int k) {
    vector<int> answer;
    
    for (int i = 0; i < arr.size(); i++)
    {
        answer.push_back(k % 2 ? arr[i] * k : arr[i] + k);
    }
    
    return answer;
}