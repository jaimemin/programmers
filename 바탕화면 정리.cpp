#include <string>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 50;

vector<int> solution(vector<string> wallpaper) {
    int minY = MAX, minX = MAX;
    int maxY = -1, maxX = -1;
    
    for (int y = 0; y < wallpaper.size(); y++)
    {
        for (int x = 0; x < wallpaper[0].size(); x++)
        {
            if (wallpaper[y][x] == '.')
            {
                continue;
            }
            
            minY = min(minY, y);
            minX = min(minX, x);
            maxY = max(maxY, y);
            maxX = max(maxX, x);
        }
    }
    
    return { minY, minX, maxY + 1, maxX + 1 };
}
