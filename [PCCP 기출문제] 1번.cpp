#include <string>
#include <vector>
using namespace std;

int solution(vector<int> bandage, int health, vector<vector<int>> attacks) {
    int answer = health;
    int idx = 0;
    int lastIdx = attacks.size() - 1;
    int consecutive = 0;
    
    for (int time = 1; time <= attacks[lastIdx][0]; time++)
    {
        if (attacks[idx][0] == time)
        {
            answer -= attacks[idx++][1];
            
            if (answer <= 0)
            {
                return -1;
            }
            
            consecutive = 0;
            
            continue;
        }
        
        answer = min(answer + bandage[1], health);
        
        if (++consecutive == bandage[0])
        {
            answer = min(answer + bandage[2], health);
            
            consecutive = 0;
        }
    }
    
    return answer;
}
