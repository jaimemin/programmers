#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> stk;

    for (int i = 0; i < arr.size();)
    {
        if (stk.empty())
        {
            stk.push_back(arr[i++]);

            continue;
        }

        int back = stk.back();

        if (back < arr[i])
        {
            stk.push_back(arr[i++]);
        }
        else
        {
            stk.pop_back();
        }
    }

    return stk;
}