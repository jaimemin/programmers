#include <string>
#include <vector>
#include <cmath>
using namespace std;

int solution(int n) {
    int root = sqrt(n);

    return root * root == n ? 1 : 2;
}