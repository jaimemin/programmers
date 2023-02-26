#include <string>
#include <vector>
#include <algorithm>
using namespace std;

const int SIZE = 3;

typedef struct
{
    int oCnt, xCnt;
} State;

State getWinnerCnts(vector<string> &board)
{
    int oCnt = 0;
    int xCnt = 0;
    
    if (board[0][0] != '.' 
        && board[0][0] == board[1][1] 
        && board[0][0] == board[2][2])
    {
        board[0][0] == 'O' ? oCnt++ : xCnt++;
    }
    
    if (board[0][2] != '.' 
        && board[0][2] == board[1][1] 
        && board[0][2] == board[2][0])
    {
        board[0][2] == 'O' ? oCnt++ : xCnt++;
    }
    
    for (int y = 0; y < SIZE; y++)
    {
        if (board[y][0] != '.' 
            && board[y][0] == board[y][1] 
            && board[y][0] == board[y][2])
        {
            board[y][0] == 'O' ? oCnt++ : xCnt++;
        }
    }
    
    for (int x = 0; x < SIZE; x++)
    {
        if (board[0][x] != '.' 
            && board[0][x] == board[1][x] 
            && board[0][x] == board[2][x])
        {
            board[0][x] == 'O' ? oCnt++ : xCnt++;
        }
    }
    
    return {oCnt, xCnt};
}

State getOXCnts(vector<string> &board)
{
    int oCnt = 0;
    int xCnt = 0;
    
    for (int y = 0; y < SIZE; y++)
    {
        for (int x = 0; x < SIZE; x++)
        {
            if (board[y][x] == 'O')
            {
                oCnt++;
            }
            
            if (board[y][x] == 'X')
            {
                xCnt++;
            }
        }
    }
    
    return {oCnt, xCnt};
}

int solution(vector<string> board) {
    State oXCnts = getOXCnts(board);
    State winnerOXCnts = getWinnerCnts(board);
    
    if (oXCnts.xCnt > oXCnts.oCnt 
        || oXCnts.oCnt - oXCnts.xCnt >= 2)
    {
        return 0;
    }
    
    if (winnerOXCnts.oCnt == 1 
        && oXCnts.oCnt != oXCnts.xCnt + 1)
    {
        return 0;
    }
    
    if (winnerOXCnts.xCnt == 1 
        && oXCnts.oCnt != oXCnts.xCnt)
    {
        return 0;
    }
    
    return 1;
}
