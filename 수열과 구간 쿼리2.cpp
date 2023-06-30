#include <string>
#include <vector>
#include <climits>
using namespace std;

vector<int> solution(vector<int> arr, vector<vector<int>> queries) {
    vector<int> answer;

    for (vector<int> query : queries)
    {
        int temp = INT_MAX;

        for (int i = query[0]; i <= query[1]; i++)
        {
            if (arr[i] > query[2])
            {
                temp = min(temp, arr[i]);
            }
        }

        answer.push_back(temp == INT_MAX ? -1 : temp);
    }

    return answer;
}