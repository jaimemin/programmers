#include <string>
#include <vector>
#include <iostream>
using namespace std;

string solution(string my_string, vector<vector<int>> queries) {
    for (vector<int> query : queries)
    {
        for (int i = query[0]; i <= (query[1] + query[0]) / 2; i++)
        {
            swap(my_string[i], my_string[query[1] - i + query[0]]);
        }
    }

    return my_string;
}