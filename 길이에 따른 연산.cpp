#include <string>
#include <vector>

using namespace std;

int solution(vector<int> num_list) {
    int size = num_list.size();
    int answer = size >= 11 ? 0 : 1;
    
    for (int i = 0; i < size; i++)
    {
        answer = size >= 11 ? answer + num_list[i] : answer * num_list[i];
    }
    
    return answer;
}