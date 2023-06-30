#include <string>
#include <vector>

using namespace std;

int solution(vector<int> num_list) {
    string odd = "";
    string even = "";

    for (int num : num_list)
    {
        num % 2 ? odd += to_string(num) : even += to_string(num);
    }

    return stoi(odd) + stoi(even);
}