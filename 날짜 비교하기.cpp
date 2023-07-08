#include <string>
#include <vector>
#include <iostream>
using namespace std;

string getNum(int i)
{
    string s = to_string(i);

    return s.length() == 2 ? s : "0" + s;
}

int solution(vector<int> date1, vector<int> date2) {
    string date1str = "";
    string date2str = "";

    for (int i = 0; i < 3; i++)
    {
        date1str += getNum(date1[i]);
        date2str += getNum(date2[i]);
    }

    cout << date1str << " " << date2str << "\n";

    if (date1str.length() > date2str.length())
    {
        return 0;
    }
    else if (date1str.length() < date2str.length())
    {
        return 1;
    }

    return date1str < date2str;
}