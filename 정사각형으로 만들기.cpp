#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr) {
    vector<vector<int>> answer;
    int row = arr.size();
    int col = arr[0].size();
    int N = max(row, col);

    answer.resize(N);

    for (int i = 0; i < N; i++)
    {
        answer[i].resize(N);
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            answer[i][j] = ((i >= row || j >= col) ? 0 : arr[i][j]);
        }
    }

    return answer;
}