#include <iostream>

using namespace std;

int main(void) {
    int year, answer;
    string age_type;
    cin >> year >> age_type;

    if (age_type == "Korea") {
        answer = 2030 - (int) year + 1;
    }
    else if (age_type == "Year") {
        answer = 2030 - (int) year;
    }

    cout << answer << endl;
    return 0;
}
