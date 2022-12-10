#include <string>
#include <vector>

using namespace std;

int solution(vector<int> common) {
    int last = common[common.size() - 1];
    int diff = common[1] - common[0];
    int diff2 = common[2] - common[1];
    int div = common[1] / common[0];

    if (diff == diff2)
    {
        return last + diff;
    }

    return last * div;
}