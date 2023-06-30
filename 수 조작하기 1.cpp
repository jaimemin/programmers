#include <string>
#include <vector>

using namespace std;

int solution(int n, string control) {
    for (char c : control)
    {
        switch (c)
        {
        case 'w':
            n++;

            break;
        case 's':
            n--;

            break;
        case 'd':
            n += 10;

            break;
        case 'a':
            n -= 10;

            break;
        }
    }

    return n;
}