#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> woobak;

void init(int k)
{
    woobak.push_back(k);

    while (k > 1)
    {
        k = k % 2 ? 3 * k + 1 : k / 2;

        woobak.push_back(k);
    }
}

vector<double> solution(int k, vector<vector<int>> ranges) {
    init(k);

    vector<double> answer;
    vector<double> v(woobak.size() + 1, 0);

    for (int i = 1; i < woobak.size(); i++)
    {
        double low = min(woobak[i], woobak[i - 1]);
        double high = max(woobak[i], woobak[i - 1]);
        double val = high - (high - low) / 2;

        v[i - 1] = val + (i > 1 ? v[i - 2] : 0);
    }

    int idx = woobak.size() - 1;

    for (int i = 0; i < ranges.size(); i++)
    {
        if (ranges[i][0] > ranges[i][1] + idx)
        {
            answer.push_back(-1.0);
        }
        else if (ranges[i][0] == ranges[i][1] + idx)
        {
            answer.push_back(0.0);
        }
        else
        {
            answer.push_back(v[ranges[i][1] + idx - 1] - (ranges[i][0] ? v[ranges[i][0] - 1] : 0));
        }
    }

    return answer;
}