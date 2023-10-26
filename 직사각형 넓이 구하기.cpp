#include <string>
#include <vector>
#include <map>
#include <set>
#include <iostream>
using namespace std;

int solution(vector<vector<int>> dots) {
    map<int, vector<int>> x2y, y2x;
    set<int> dotSet;
    
    for (vector<int> dot : dots)
    {
        x2y[dot[0]].push_back(dot[1]);
        y2x[dot[1]].push_back(dot[0]);

        dotSet.insert(dot[0]);
        dotSet.insert(dot[1]);
    }
    
    int xDiff = 0, yDiff = 0;
    
    for (int dot : dotSet)
    {
        if (x2y[dot].size() == 2)
        {
            yDiff = abs(x2y[dot][1] - x2y[dot][0]);
        }
        
        if (y2x[dot].size() == 2)
        {
            xDiff = abs(y2x[dot][1] - y2x[dot][0]);
        }
    }
        
    return xDiff * yDiff;
}
