#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<int> num_list, int n) {
    vector<vector<int>> answer;
    vector<int> temp;
    
    for (int num : num_list)
    {
        temp.push_back(num);
        
        if (temp.size() == n)
        {
            answer.push_back(temp);
            
            temp.clear();
        }
    }
    
    if (!temp.empty())
    {
        answer.push_back(temp);
    }
    
    return answer;
}
