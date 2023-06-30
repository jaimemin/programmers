#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> arr, vector<vector<int>> queries) {
    vector<int> answer = arr;

    for (vector<int> query : queries)
    {
        swap(answer[query[0]], answer[query[1]]);
    }

    return answer;
}