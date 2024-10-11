#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> cpr) {
    vector<int> answer = {0, 0, 0, 0, 0};
    vector<string> basic_order = {"check", "call", "pressure", "respiration", "repeat"};

    for(int i=0; i < cpr.size(); i++) {
        for(int j=0; j< basic_order.size(); j++) {
            if(cpr[i] == basic_order[j]){
                answer[i] = j + 1;
                break;
            }
        }
    }

    return answer;
}
