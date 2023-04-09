#include <string>
#include <vector>
using namespace std;

bool isObstacle(pair<int, int> temp, vector<string> &park)
{
    return park[temp.first][temp.second] == 'X';
}

vector<int> solution(vector<string> park, vector<string> routes) {
    pair<int, int> coord;
    
    for (int y = 0; y < park.size(); y++)
    {
        for (int x = 0; x < park[0].size(); x++)
        {
            if (park[y][x] == 'S')
            {
                coord = { y, x };
            }
        }
    }
    
    for (string route : routes)
    {
        char dir = route[0];
        int cnt = stoi(route.substr(2));
        bool flag = true;
        pair<int, int> temp = coord;
        
        while (cnt--)
        {
            switch(dir)
            {
                case 'E':
                    temp.second++;
                    
                    if (temp.second == park[0].size() 
                        || isObstacle(temp, park))
                    {
                        flag = false;
                    }

                    break;
                case 'W':
                    temp.second--;
                    
                    if (temp.second == -1 
                        || isObstacle(temp, park))
                    {
                        flag = false;
                    }

                    break;
                case 'N':
                    temp.first--;
                    
                    if (temp.first == -1 
                        || isObstacle(temp, park))
                    {
                        flag = false;
                    }

                    break;
                case 'S':
                    temp.first++;
                    
                    if (temp.first == park.size()
                        || isObstacle(temp, park))
                    {
                        flag = false;
                    }

                    break;
            }
            
            if (!flag)
            {
                break;
            }
        }
        
        coord = flag ? temp : coord;
    }
    
    return { coord.first, coord.second };
}
