#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> num_list) {
    vector<int> answer = num_list;
    int len = answer.size();

    if (answer[len - 1] > answer[len - 2])
    {
        answer.push_back(answer[len - 1] - answer[len - 2]);
    }
    else
    {
        answer.push_back(answer[len - 1] * 2);
    }

    return answer;
}