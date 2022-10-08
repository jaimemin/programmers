#include <string>
#include <vector>

using namespace std;

int solution(vector<int> array, int height) {
    int answer = 0;

    for (int num : array) {
        answer += (num > height);
    }

    return answer;
}