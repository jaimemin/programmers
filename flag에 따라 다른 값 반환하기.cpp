#include <string>
#include <vector>

using namespace std;

int solution(int a, int b, bool flag) {
    int answer = flag ? a + b : a - b;

    return answer;
}