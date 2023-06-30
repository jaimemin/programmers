#include <string>
#include <vector>

using namespace std;

int solution(int a, int d, vector<bool> included) {
    int answer = 0;

    for (bool include : included)
    {
        answer += include ? a : 0;

        a += d;
    }

    return answer;
}