#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool func(int size, int row, int col, const vector<vector<string>>& park) {
    int parkRows = park.size();
    int parkCols = park[0].size();

    if (row + size > parkRows || col + size > parkCols) 
    {
        return false;
    }

    for (int i = row; i < row + size; i++) 
    {
        for (int j = col; j < col + size; j++) 
        {
            if (park[i][j] != "-1")
            {
                return false;
            }
        }
    }
    
    return true;
}

int solution(vector<int> mats, vector<vector<string>> park) {
    int parkRows = park.size();
    int parkCols = park[0].size();
    
    sort(mats.rbegin(), mats.rend());
    
    for (int matSize : mats) 
    {
        for (int i = 0; i < parkRows; i++) 
        {
            for (int j = 0; j < parkCols; j++) 
            {
                if (func(matSize, i, j, park))
                {
                    return matSize;
                }
            }
        }
    }
    
    return -1;
}
