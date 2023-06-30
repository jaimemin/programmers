#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int solution(int a, int b) {
    int aLength = to_string(a).length();
    int bLength = to_string(b).length();
    int answer = max(a * pow(10, bLength) + b, b * pow(10, aLength) + a);

    return answer;
}