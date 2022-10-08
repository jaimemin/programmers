#include <string>
#include <vector>

using namespace std;

int solution(int n, int k) {
    int serviceCnt = n / 10;

    return n * 12000 + (k - serviceCnt) * 2000;
}