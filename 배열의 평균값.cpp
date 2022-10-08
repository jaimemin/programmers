#include <string>
#include <vector>

using namespace std;

double solution(vector<int> numbers) {
    double answer = 0;

    for (int number : numbers) {
        answer += number;
    }

    return answer / numbers.size();
}