#include <string>
#include <vector>
#include <cmath>
using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer;
    
    for (int num : arr)
    {
        answer.push_back(num);
    }
    
    int targetLength = arr.size();
    int len = 0;
    
    while (targetLength)
    {
        targetLength /= 2;
    
        len++;
    }
    
    if (pow(2, len - 1) != answer.size())
    {
        for (int i = answer.size(); i < pow(2, len); i++)
        {
            answer.push_back(0);
        }
    }
    
    return answer;
}