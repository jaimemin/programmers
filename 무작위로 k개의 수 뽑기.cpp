#include <string>
#include <vector>
#include <set>
using namespace std;

vector<int> solution(vector<int> arr, int k) {
    vector<int> answer;
    set<int> visited;
    
    for (int num : arr)
    {
        if (visited.find(num) != visited.end())
        {
            continue;
        }
        
        answer.push_back(num);
        visited.insert(num);
    }
    
    while (answer.size() > k && answer.size() != k)
    {
        answer.pop_back();
    }
    
    while (answer.size() < k && answer.size() != k)
    {
        answer.push_back(-1);
    }
    
    return answer;
}