#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, vector<int> slicer, vector<int> num_list) {
    int a = slicer[0];
    int b = slicer[1];
    int c = slicer[2];
    vector<int> answer;
    
    switch (n)
    {
        case 1:
            for (int i = 0; i <= b; i++)
            {
                answer.push_back(num_list[i]);
            }
            
            break;
        case 2:
            for (int i = a; i < num_list.size(); i++)
            {
                answer.push_back(num_list[i]);
            }
            
            break;
        case 3:
            for (int i = a; i <= b; i++)
            {
                answer.push_back(num_list[i]);
            }
            
            break;
        case 4:
            for (int i = a; i <= b; i += c)
            {
                answer.push_back(num_list[i]);
            }
            
            break;
    }
    
    return answer;
}