#include <string>
#include <vector>

using namespace std;

typedef struct
{
    int y, x;
} Dir;

Dir moveDir[4] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

int solution(vector<vector<string>> board, int h, int w) {
    int answer = 0;
    
    for (int k = 0; k < 4; k++)
    {
        int nextH = h + moveDir[k].y;
        int nextW = w + moveDir[k].x;
        
        if (nextH < 0 || nextH >= board.size() || nextW < 0 || nextW >= board.size())
        {
            continue;
        }
        
        answer += (board[h][w] == board[nextH][nextW]);
    }
    
    return answer;
}
