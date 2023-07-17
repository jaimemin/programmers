#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;

map<string, int> s2int;

void init()
{
    s2int["zero"] = 0;
    s2int["one"] = 1;
    s2int["two"] = 2;
    s2int["three"] = 3;
    s2int["four"] = 4;
    s2int["five"] = 5;
    s2int["six"] = 6;
    s2int["seven"] = 7;
    s2int["eight"] = 8;
    s2int["nine"] = 9;
}

long long solution(string numbers) {
    init();

    long long answer = 0;
    string temp = "";

    for (char c : numbers)
    {
        temp += c;

        if (s2int.count(temp) != 0)
        {
            answer *= 10;
            answer += s2int[temp];
            cout << temp << " " << answer << "\n";
            temp = "";
        }
    }

    return answer;
}