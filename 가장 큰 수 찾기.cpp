#include <string>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b)
{
    return a.first > b.first;
}

vector<int> solution(vector<int> array) {
    vector<pair<int, int>> v;

    for (int i = 0; i < array.size(); i++)
    {
        v.push_back({ array[i], i });
    }

    sort(v.begin(), v.end(), cmp);

    vector<int> answer;
    answer.push_back(v[0].first);
    answer.push_back(v[0].second);

    return answer;
}