#include <string>
#include <vector>

using namespace std;

int solution(vector<int> numbers, int k) {
    int answer = ((k * 2) - 1) % numbers.size();
    
    return answer == 0 ? numbers.size() : answer;
}
