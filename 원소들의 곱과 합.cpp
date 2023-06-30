#include <string>
#include <vector>

using namespace std;

int solution(vector<int> num_list) {
    long long multiply = 1;
    long long sum = 0;

    for (int num : num_list)
    {
        multiply *= num;
        sum += num;
    }

    return sum * sum > multiply;
}