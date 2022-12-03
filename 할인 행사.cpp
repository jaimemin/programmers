#include <string>
#include <vector>
#include <map>
#include <set>
using namespace std;

set<string> keys;

map<string, int> required;

map<string, int> cur;

void init(vector<string>& want, vector<int>& number)
{
    for (int i = 0; i < want.size(); i++)
    {
        keys.insert(want[i]);
        required[want[i]] = number[i];
    }
}

bool isQualified()
{
    for (string key : keys)
    {
        if (cur[key] < required[key])
        {
            return false;
        }
    }

    return true;
}

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    init(want, number);

    for (int i = 0; i < 10; i++)
    {
        cur[discount[i]]++;
    }

    int answer = 0;

    if (isQualified())
    {
        answer++;
    }

    for (int i = 0, j = 10; j < discount.size(); i++, j++)
    {
        cur[discount[i]]--;
        cur[discount[j]]++;

        if (isQualified())
        {
            answer++;
        }
    }

    return answer;
}