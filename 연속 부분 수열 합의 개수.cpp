#include <string>
#include <vector>
#include <set>
using namespace std;

int solution(vector<int> elements) {
    set<int> s;

    for (int i = 1; i <= elements.size(); i++)
    {
        for (int j = 0; j < elements.size(); j++)
        {
            int sum = elements[j];

            for (int k = j + 1; k < j + i; k++)
            {
                sum += elements[k % elements.size()];
            }

            s.insert(sum);
        }
    }

    return s.size();
}