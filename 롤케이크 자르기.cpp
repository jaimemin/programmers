#include <string>
#include <vector>
#include <set>
using namespace std;

const int MAX = 1e4 + 1;

int solution(vector<int> topping) {
    int answer = 0;
    int visited[MAX] = { 0, };
    set<int> st;

    for (int t : topping)
    {
        visited[t]++;
        st.insert(t);
    }

    set<int> st2;

    for (int i = 0; i < topping.size(); i++)
    {
        int t = topping[i];

        if (--visited[t] == 0)
        {
            st.erase(t);
        }

        st2.insert(t);

        if (st.size() == st2.size())
        {
            answer++;
        }
    }

    return answer;
}