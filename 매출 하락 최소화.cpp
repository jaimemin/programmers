#include <vector>
#include <stack>
#include <algorithm>
#include <climits>
using namespace std;

int solution(vector<int> sales, vector<vector<int>> links) {
    int n = sales.size();
    vector<vector<int>> children(n + 1);
    
    for (auto edge : links)
    {
        int leader = edge[0];
        int subOrdinate = edge[1];
        
        children[leader].push_back(subOrdinate);
    }
    
    // notAttendedDp[i] : i번 직원이 참석하지 않을 때, i번 노드를 루트로 하는 서브트리에서의 최소 비용
    // attendedDp[i] : i번 직원이 참석했을 때, ... (매출액을 비용으로 계산)
    vector<long long> notAttendedDp(n + 1, 0);
    vector<long long> attendedDp(n + 1, 0);
    
    // 각 스택 원소는 {node, nextChildIndex}를 저장
    stack<pair<int,int>> st;
    st.push({1, 0}); // CEO부터
    
    while (!st.empty())
    {
        auto &top = st.top();
        int node = top.first;
        int &childIdx = top.second;
        
        if (childIdx < children[node].size())
        {
            // 아직 처리하지 않은 자식이 있으면 그 자식을 DFS에 넣음.
            int child = children[node][childIdx++];

            st.push({child, 0});
        } 
        else 
        {
            // node의 모든 자식을 처리한 후 postorder로 dp값 계산
            st.pop();
            
            // 리프 노드: 팀장이 아니므로 참석하지 않아도 제약 없음
            if (children[node].empty())
            {
                notAttendedDp[node] = 0;
                attendedDp[node] = sales[node - 1];
            }
            // node가 팀장인 경우
            else 
            {
                long long sumAttended = sales[node-1];
                long long sumNotAttended = 0;
                bool anyChildSelected = false;
                long long extra = LLONG_MAX;
                
                for (int child : children[node]) 
                {
                    long long notSelected = notAttendedDp[child];
                    long long selected = attendedDp[child];
                    long long childMin = min(notSelected, selected);
                    sumAttended += childMin;
                    sumNotAttended += childMin;
                    
                    if (selected <= notSelected)
                    {
                        anyChildSelected = true;
                    } 
                    else 
                    {
                        extra = min(extra, selected - notSelected);
                    }
                }
                
                // 만약 node가 참석하지 않았을 때, 자식들 모두 비참석 상태라면
                // 최소 추가 비용을 더해 한 자식은 참석하도록 함
                if (!anyChildSelected)
                {
                    sumNotAttended += extra;
                }
                
                notAttendedDp[node] = sumNotAttended;
                attendedDp[node] = sumAttended;
            }
        }
    }
    
    long long ans = min(notAttendedDp[1], attendedDp[1]);
    
    return (int)ans;
}
