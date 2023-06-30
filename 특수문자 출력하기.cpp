#include <iostream>

using namespace std;

int main(void) {
    string output = "!@#$%^&*(\\'\"";
    string output2 = "<>?:;";
    output += output2;
    cout << output << "\n";

    return 0;
}