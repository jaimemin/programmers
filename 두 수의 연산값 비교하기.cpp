#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int solution(int a, int b) {
    int bLength = to_string(b).length();
    int answer = max(a * (int)pow(10, bLength) + b, a * b * 2);

    return answer;
}