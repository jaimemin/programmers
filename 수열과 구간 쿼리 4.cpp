#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr, vector<vector<int>> queries) {
    vector<int> answer = arr;
    
    for (vector<int> query : queries)
    {
        for (int i = query[0]; i <= query[1]; i++)
        {
            if (i % query[2] == 0)
            {
                answer[i]++;
            }
        }
    }
    
    return answer;
}
