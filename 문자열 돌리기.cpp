#include <iostream>
#include <string>

using namespace std;

int main(void) {
    string str;
    cin >> str;

    for (char c : str)
    {
        cout << c << "\n";
    }

    return 0;
}