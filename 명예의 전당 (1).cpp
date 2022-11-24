#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
using namespace std;

vector<int> solution(int k, vector<int> score) {
    vector<int> answer;
    priority_queue<int> maxPq;

    for (int num : score)
    {
        maxPq.push(num);
        priority_queue<int> temp;
        int score = 0;
        int size = maxPq.size();

        for (int i = 0; i < min(k, size); i++)
        {
            temp.push(maxPq.top());
            score = maxPq.top();

            maxPq.pop();
        }

        maxPq = temp;
        answer.push_back(score);
    }

    return answer;
}