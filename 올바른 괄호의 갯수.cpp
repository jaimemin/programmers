#include <string>
#include <vector>

using namespace std;

int solution(int N) {
    vector<int> v(N + 1, 0);
    v[0] = 1;

    for (int num = 1; num <= N; num++) 
    {
        for (int i = 0; i < num; i++) 
        {
            v[num] += v[i] * v[num - (i + 1)];
        }
    }

    return v[N];
}
