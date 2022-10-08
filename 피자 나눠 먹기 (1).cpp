#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    return n / 7 + (n % 7 ? 1 : 0);
}