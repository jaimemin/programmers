#include <iostream>
#include <string>

using namespace std;

int main(void) {
    string str;
    cin >> str;
    
    for (int i = 0; i < str.length(); i++)
    {
        str[i] = str[i] >= 'a' ? toupper(str[i]) : tolower(str[i]);
    }
    
    cout << str << "\n";
    
    return 0;
}
