#include <string>
#include <vector>

using namespace std;

int solution(int storey) {
    int answer = 0;

    while (storey)
    {
        int carry = storey % 10;
        int digit = (storey / 10) % 10;

        if (carry > 5)
        {
            answer += 10 - carry;
            storey += 10;
        }
        else if (carry == 5)
        {
            answer += 5;
            storey += digit >= 5 ? 10 : 0;
        }
        else
        {
            answer += carry;
        }

        storey /= 10;
    }

    return answer;
}