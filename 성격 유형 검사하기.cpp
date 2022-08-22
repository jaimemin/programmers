#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

const int MAX = 26;

int alpha[MAX];

map<int, vector<char>> idx2types;

void init()
{
    idx2types[1] = { 'R', 'T' };
    idx2types[2] = { 'C', 'F' };
    idx2types[3] = { 'J', 'M' };
    idx2types[4] = { 'A', 'N' };
}

string solution(vector<string> survey, vector<int> choices) {
    init();

    for (int i = 0; i < survey.size(); i++)
    {
        if (choices[i] < 4)
        {
            alpha[survey[i][0] - 'A'] += 4 - choices[i];
        }
        else if (choices[i] > 4)
        {
            alpha[survey[i][1] - 'A'] += abs(4 - choices[i]);
        }
    }

    string answer = "";

    for (int i = 1; i <= 4; i++)
    {
        char a = idx2types[i][0];
        char b = idx2types[i][1];

        if (alpha[a - 'A'] >= alpha[b - 'A'])
        {
            answer += a;
        }
        else
        {
            answer += b;
        }
    }

    return answer;
}