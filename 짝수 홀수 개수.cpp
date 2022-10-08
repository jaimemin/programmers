#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> num_list) {
    int odd = 0, even = 0;

    for (int num : num_list) {
        num % 2 ? odd++ : even++;
    }

    return { even, odd };
}