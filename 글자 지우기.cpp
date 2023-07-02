#include <string>
#include <vector>
#include <set>
using namespace std;

string solution(string my_string, vector<int> indices) {
    set<int> idxs;

    for (int indice : indices)
    {
        idxs.insert(indice);
    }

    string answer = "";

    for (int i = 0; i < my_string.length(); i++)
    {
        if (idxs.find(i) == idxs.end())
        {
            answer += my_string[i];
        }
    }

    return answer;
}