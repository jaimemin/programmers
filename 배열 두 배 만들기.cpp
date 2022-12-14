#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;

    for (int number : numbers)
    {
        answer.push_back(number * 2);
    }

    return answer;
}