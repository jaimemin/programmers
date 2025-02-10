#include <vector>
#include <string>

using namespace std;

int convert(int time) 
{
    int hour = time / 100;
    int minute = time % 100;
    
    return hour * 60 + minute;
}

int solution(vector<int> schedules, vector<vector<int>> timelogs, int startday) {
    int answer = 0;
    int n = schedules.size();
    
    for (int i = 0; i < n; i++) {
        
        bool qualify = true;
        int scheduledMinutes = convert(schedules[i]);
        int allowed = scheduledMinutes + 10;

        for (int j = 0; j < 7; j++) 
        {
            int currentDay = ((startday - 1) + j) % 7 + 1;

            if (currentDay == 6 || currentDay == 7)
            {
                continue;
            }
            
            int checkMinutes = convert(timelogs[i][j]);
            
            if (checkMinutes > allowed) 
            {
                qualify = false;
                
                break;
            }
        }
        
        if (qualify)
        {
            answer++;
        }
    }
    
    return answer;
}
