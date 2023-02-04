#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <iostream>
using namespace std;

int convertToInt(string s, bool isEndTime)
{
    int hour = stoi(s.substr(0, 2));
    int minute = stoi(s.substr(3, 2));
    
    if (isEndTime)
    {
        if (minute >= 50)
        {
            hour += 1;
            minute -= 50;
        }
        else
        {
            minute += 10;
        }
    }
    
    return hour * 100 + minute;
}

int solution(vector<vector<string>> book_time) {
    vector<pair<int, int>> v;
    
    for (vector<string> time : book_time)
    {
        int start = convertToInt(time[0], false);
        int end = convertToInt(time[1], true);
        
        v.push_back({start, end});
    }
    
    sort(v.begin(), v.end());
    
    int answer = 0;
    vector<pair<int, int>> filled;
    
    for (pair<int, int> time : v)
    {
        int start = time.first;
        vector<pair<int, int>> temp;
        
        for (pair<int ,int> room : filled)
        {
            if (start < room.second)
            {
                temp.push_back(room);
            }
        }
        
        filled = temp;
        filled.push_back(time);
        answer = max(answer, (int) filled.size());
    }
    
    return answer;
}
