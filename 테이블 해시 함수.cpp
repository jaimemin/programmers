#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

typedef struct
{
    int idx;
    int first;
    int col;
} State;

bool cmp(State a, State b)
{
    if (a.col != b.col)
    {
        return a.col < b.col;
    }

    return a.first > b.first;
}

int solution(vector<vector<int>> data, int col, int row_begin, int row_end) {
    vector<State> v;
    int idx = 0;

    for (vector<int> d : data)
    {
        v.push_back({ idx++, d[0], d[col - 1] });
    }

    // 두 번째 단계
    sort(v.begin(), v.end(), cmp);

    int answer = 0;

    // 세 번째 단계 및 네 번째 단계
    for (int i = 0; i < data[v[row_begin - 1].idx].size(); i++)
    {
        answer += data[v[row_begin - 1].idx][i] % row_begin;
    }

    for (int i = row_begin; i < row_end; i++)
    {
        int temp = 0;

        for (int j = 0; j < data[v[i].idx].size(); j++)
        {
            temp += data[v[i].idx][j] % (i + 1);
        }

        answer ^= temp; // XOR
    }

    return answer;
}