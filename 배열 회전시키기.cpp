#include <string>
#include <vector>
#include <deque>
using namespace std;

vector<int> solution(vector<int> numbers, string direction) {
    vector<int> answer;
    deque<int> dq;
    
    for (int num : numbers)
    {
        dq.push_back(num);
    }
    
    if (direction == "left")
    {
        int num = dq.front();
        dq.pop_front();
        
        dq.push_back(num);
    }
    else
    {
        int num = dq.back();
        dq.pop_back();
        
        dq.push_front(num);
    }
    
    for (int num : dq)
    {
        answer.push_back(num);
    }
    
    return answer;
}
