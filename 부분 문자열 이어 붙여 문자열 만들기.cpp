#include <string>
#include <vector>

using namespace std;

string solution(vector<string> my_strings, vector<vector<int>> parts) {
    string answer = "";

    for (int i = 0; i < parts.size(); i++)
    {
        string s = my_strings[i];
        int startIdx = parts[i][0];
        int endIdx = parts[i][1];

        answer += s.substr(startIdx, endIdx - startIdx + 1);
    }

    return answer;
}