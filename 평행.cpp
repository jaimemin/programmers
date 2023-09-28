#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(vector<vector<int>> dots) {
    for (int i = 0; i < 2; i++)
    {
        for (int j = i + 1; j < 4; j++)
        {
            int visited[4] = {0, };
            visited[i] = true;
            visited[j] = true;
            
            double xDiff = abs(dots[i][0] - dots[j][0]);
            double yDiff = abs(dots[i][1] - dots[j][1]);
            double inclination = xDiff / yDiff;
            
            vector<int> v;
            
            for (int k = 0; k < 4; k++)
            {
                if (!visited[k])
                {
                    v.push_back(k);
                }
            }
            
            double xDiff2 = abs(dots[v[0]][0] - dots[v[1]][0]);
            double yDiff2 = abs(dots[v[0]][1] - dots[v[1]][1]);
            double inclination2 = xDiff2 / yDiff2;
            
            if (inclination != inclination2)
            {
                continue;
            }
            
            return 1;
        }
    }
    
    return 0;
}
