#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<vector<int>> solution(int n) {
    vector<vector<int>> answer;
    answer.resize(n);
    
    for (int i = 0; i < n; i++)
    {
        answer[i].resize(n);
    }
    
    int row = 0, col = 0;
    int num = 1;
    
    for (int i = 0; i < n; i++)
    {
        answer[row][col++] = num++;
    }
    
    col--;
    
    bool mod = n % 2;
    
    for (int i = n - 1; i >= 1; i--)
    {
        for (int j = 1; j <= i; j++)
        {
            row = row + (i % 2 == mod ? -1 : 1);
            
            answer[row][col] = num++;
        }
        
        for (int j = 1; j <= i; j++)
        {
            col = col + (i % 2 == mod ? 1 : -1);
            
            answer[row][col] = num++;
        }
    }
    
    return answer;
}