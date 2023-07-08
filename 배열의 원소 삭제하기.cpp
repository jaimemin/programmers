#include <string>
#include <vector>
#include <set>
using namespace std;

vector<int> solution(vector<int> arr, vector<int> delete_list) {
    vector<int> answer;
    set<int> toDelete;

    for (int d : delete_list)
    {
        toDelete.insert(d);
    }

    for (int num : arr)
    {
        if (toDelete.find(num) != toDelete.end())
        {
            continue;
        }

        answer.push_back(num);
    }


    return answer;
}