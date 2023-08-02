#include <string>
#include <vector>

using namespace std;

typedef struct
{
    int y, x;
} Dir;

Dir moveDir[8] = {{1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}, {-1, 0}, {-1, 1}, {0, 1}};

int solution(vector<vector<int>> board) {
    int answer = 0;
    
    for (int y = 0; y < board.size(); y++)
    {
        for (int x = 0; x < board[y].size(); x++)
        {
            if (board[y][x])
            {
                continue;
            }
            
            bool flag = true;
            
            for (int k = 0; k < 8; k++)
            {
                int nextY = y + moveDir[k].y;
                int nextX = x + moveDir[k].x;
                
                if (nextY < 0 || nextY >= board.size() || nextX < 0 || nextX >= board[y].size())
                {
                    continue;
                }
                
                if (board[nextY][nextX])
                {
                    flag = false;
                    
                    break;
                }
            }
            
            answer += flag;
        }
    }
    
    return answer;
}
