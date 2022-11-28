#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(int a, int b, int n) {
    int answer = 0;

    while (n >= a) {
        int temp = n / a;
        answer += temp * b;
        n = (temp * b) + (n % a);
    }

    return answer;
}