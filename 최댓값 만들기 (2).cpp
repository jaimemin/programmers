#include <string>
#include <vector>
#include <algorithm>>
using namespace std;

int solution(vector<int> numbers) {
    sort(numbers.begin(), numbers.end());
    int len = numbers.size();
    
    return max(numbers[0] * numbers[1], numbers[len - 1] * numbers[len - 2]);   
}
