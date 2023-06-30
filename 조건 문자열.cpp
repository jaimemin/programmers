#include <string>
#include <vector>

using namespace std;

int solution(string ineq, string eq, int n, int m) {
    if (ineq == "<")
    {
        return eq == "=" ? n <= m : n < m;
    }
    else
    {
        return eq == "=" ? n >= m : n > m;
    }
}