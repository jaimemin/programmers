#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<vector<int>> gameBoard;

int boardSize;

// 각 열에서 "제일 위쪽 블록의 행 번호"를 저장
vector<int> topRowInCol;

void updateTopRow(int col) 
{
    int row = 0;
    
    for (; row < boardSize; row++) 
    {
        if (gameBoard[row][col] != 0) 
        {
            break;
        }
    }
    
    topRowInCol[col] = row;
}

bool removeBlock3x2(int col) 
{
    if (col + 1 >= boardSize)
    {
        return false;
    }
    
    int maxRow = max(topRowInCol[col], topRowInCol[col + 1]);

    if (maxRow < 2 || maxRow >= boardSize) 
    {
        return false;
    }

    int val = gameBoard[maxRow][col];
    int blankCnt = 0;

    for (int r = maxRow; r >= maxRow - 2; r--) 
    {
        for (int c = col; c <= col + 1; c++)
        {
            if (gameBoard[r][c] != 0 && gameBoard[r][c] != val)
            {
                return false;
            }
            
            if (gameBoard[r][c] == 0) 
            {
                blankCnt++;
            }
        }
    }
    
    // 빈 칸이 정확히 2개여야 함
    if (blankCnt != 2)
    {
        return false;
    }

    // 블록 제거
    for (int r = maxRow; r >= maxRow - 2; r--) 
    {
        for (int c = col; c <= col + 1; c++) 
        {
            gameBoard[r][c] = 0;
        }
    }

    for (int c = col; c <= col + 1; c++)
    {
        updateTopRow(c);
    }

    return true;
}

bool removeBlock2x3(int col) 
{
    if (col + 2 >= boardSize)
    {
        return false;
    }
    
    vector<int> rows = { topRowInCol[col], topRowInCol[col + 1], topRowInCol[col + 2] };
    int maxRow = -1;
    int minRow = boardSize * 2;
    
    for (int row : rows)
    {
        maxRow = max(maxRow, row);
        minRow = min(minRow, row);
    }

    int sameMaxRowCnt = 0;
    
    for (int row : rows)
    {
        if (row == maxRow)
        {
            sameMaxRowCnt++;
        }
    }
    
    if (sameMaxRowCnt != 2) 
    {
        return false;
    }
    
    if (minRow < 0 || maxRow >= boardSize)
    {
        return false;
    }
    
    if (maxRow < 1) 
    {
        return false;
    }
    
    int val = gameBoard[maxRow][col];
    int blankCnt = 0;

    for (int r = maxRow - 1; r <= maxRow; r++) 
    {
        for (int c = col; c <= col + 2; c++) 
        {
            if (gameBoard[r][c] != 0 && gameBoard[r][c] != val) 
            {
                return false;
            }
            
            if (gameBoard[r][c] == 0) 
            {
                blankCnt++;
            }
        }
    }

    if (blankCnt != 2)
    {
        return false;
    }

    // 블록 제거
    for (int r = maxRow - 1; r <= maxRow; r++)
    {
        for (int c = col; c <= col + 2; c++)
        {
            gameBoard[r][c] = 0;
        }
    }

    for (int x = col; x <= col + 2; x++)
    {
        updateTopRow(x);
    }

    return true;
}

int solution(vector<vector<int>> board) {
    gameBoard = board;
    boardSize = board.size();
    topRowInCol.assign(boardSize, 0);
    
    for (int col = 0; col < boardSize; col++) 
    {
        updateTopRow(col);
    }

    int answer = 0;

    while (true) 
    {
        int removeCnt = 0;

        for (int col = 0; col < boardSize; col++) 
        {
            if (removeBlock3x2(col)) 
            {
                removeCnt++;
            }
            
            if (removeBlock2x3(col))
            {
                removeCnt++;
            }
        }

        if (removeCnt == 0) 
        {
            break;
        }
        
        answer += removeCnt;
    }

    return answer;
}
