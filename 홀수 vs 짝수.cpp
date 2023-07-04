#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> num_list) {
    int odd = 0, even = 0;
    
    for (int i = 0; i < num_list.size(); i++)
    {
        i % 2 ? even += num_list[i] : odd += num_list[i];
    }
    
    return max(odd, even);
}