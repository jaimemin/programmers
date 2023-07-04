#include <string>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer;
    bool start = false;
    stack<int> st;
    
    for (int num : arr)
    {
        if (num == 2)
        {
            start = true;
        }
        
        if (start)
        {
            st.push(num);
        }
    }
    
    while (!st.empty())
    {
        if (st.top() == 2)
        {
            break;
        }
        
        st.pop();
    }
    
    while (!st.empty())
    {
        answer.push_back(st.top());
        
        st.pop();
    }
    
    reverse(answer.begin(), answer.end());
    
    if (answer.empty())
    {
        answer.push_back(-1);
    }
    
    return answer;
}