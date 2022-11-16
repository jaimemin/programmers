#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string solution(vector<int> food) {
    string half = "";

    for (int i = 1; i < food.size(); i++)
    {
        if (food[i] / 2 == 0)
        {
            continue;
        }

        for (int j = 0; j < food[i] / 2; j++)
        {
            half += (i + '0');
        }
    }

    string answer = half + "0";
    reverse(half.begin(), half.end());
    answer += half;

    return answer;
}