#include <string>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 100 + 1;

int solution(vector<vector<int>> points, vector<vector<int>> routes) {
    int answer = 0;
    int numRobots = routes.size();
    vector<pair<int, int>> pointCoords(points.size() + 1);
    
    for (int i = 0; i < points.size(); i++) {
        int r = points[i][0];
        int c = points[i][1];
        
        pointCoords[i + 1] = { r, c };
    }

    vector<vector<pair<int, int>>> robotPaths(numRobots);
    int maxTime = 0;
    
    for (int i = 0; i < numRobots; i++) 
    {
        vector<int>& route = routes[i];
        vector<pair<int, int>> path;
        int currentR = pointCoords[route[0]].first;
        int currentC = pointCoords[route[0]].second;
        path.push_back({ currentR, currentC });

        for (int j = 1; j < route.size(); j++) 
        {
            int nextR = pointCoords[route[j]].first;
            int nextC = pointCoords[route[j]].second;

            while (currentR != nextR) 
            {
                if (currentR < nextR) 
                {
                    currentR++;
                }
                else 
                {
                    currentR--;
                }
                
                path.push_back({ currentR, currentC });
            }

            while (currentC != nextC) 
            {
                if (currentC < nextC) 
                {
                    currentC++;
                }
                else 
                {
                    currentC--;
                }
                
                path.push_back({ currentR, currentC });
            }
        }

        maxTime = max(maxTime, (int)path.size());
        robotPaths[i] = path;
    }

    for (int t = 0; t < maxTime; t++) 
    {
        vector<vector<int>> grid(MAX, vector<int>(MAX, 0));

        for (int i = 0; i < numRobots; i++) 
        {
            if (t < robotPaths[i].size()) 
            {
                int r = robotPaths[i][t].first;
                int c = robotPaths[i][t].second;
                
                grid[r][c]++;
            }
        }

        for (int r = 1; r < MAX; r++) 
        {
            for (int c = 1; c < MAX; c++) 
            {
                if (grid[r][c] >= 2) 
                {
                    answer++;
                }
            }
        }
    }

    return answer;
}
