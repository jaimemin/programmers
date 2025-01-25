#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<vector<int>> gameBoard;

int boardSize;

// 각 열에서 "제일 위쪽 블록의 행 번호"를 저장
vector<int> topRowInCol;

/*
     - 인자로 받은 열(col)을 위에서부터 내려오며,
       0이 아닌 값(블록)을 제일 처음으로 만나는 행(row)을 찾는다.
     - 찾은 행 번호를 topRowInCol[col]에 저장.
     - 만약 해당 열이 전부 0이면 row=boardSize까지 진행되어
       결국 topRowInCol[col]에는 boardSize가 들어갈 것임.
*/
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

/*
      - 열(col)와 (col+1) 두 열에 대해, 
        "3행 × 2열(높이3, 폭2)" 형태를 검사 후 블록 제거를 시도한다.
      - 실제 검사 범위:
         - maxRow = max( topRowInCol[col], topRowInCol[col+1] )
         - (maxRow .. maxRow-1 .. maxRow-2) 행 × (col .. col+1) 열
      - 조건:
         1) 해당 영역 내 빈 칸(0)이 정확히 2개.
         2) 빈칸이 아닌 칸은 전부 동일한 숫자(예: val) 또는 0이여야 함.
            (즉, 0이 아닌 칸은 전부 같은 블록 번호 val)
      - 만족하면 그 6칸을 전부 0으로 만들고, topRowInCol 갱신 후 true 반환.
      - 그렇지 않으면 false 반환.
*/
bool removeBlock3x2(int col) 
{
    // 범위 검사: col+1이 boardSize를 넘어가면 2열 확보 불가
    if (col + 1 >= boardSize)
    {
        return false;
    }
    
    // 두 열 각각의 "제일 위 블록 행" 중 큰 값을 maxRow로 삼는다.
    int maxRow = max(topRowInCol[col], topRowInCol[col + 1]);

    // 3행 확보 위해서 (maxRow - 2) >= 0 이어야 하고, maxRow < boardSize
    if (maxRow - 2 < 0 || maxRow >= boardSize) 
    {
        return false;
    }

    // 기준값 val: (maxRow, col)에 있는 숫자
    int val = gameBoard[maxRow][col];
    int blankCount = 0;

    // 3행 × 2열 영역 검사 (r= maxRow..(maxRow-2), c= col..col+1)
    for (int r = maxRow; r >= maxRow - 2; r--) 
    {
        for (int c = col; c <= col + 1; c++)
        {
            int cell = gameBoard[r][c];

            // cell이 0이 아니고, val과도 다르면 제거 불가
            if (cell != 0 && cell != val)
            {
                return false;
            }
            
            // 빈 칸이면 blankCount++
            if (cell == 0) 
            {
                blankCount++;
            }
        }
    }
    
    // 빈 칸이 정확히 2개여야 함
    if (blankCount != 2)
    {
        return false;
    }

    // 위 조건을 모두 만족 -> 영역을 0으로 덮어쓰기 (블록 제거)
    for (int r = maxRow; r >= maxRow - 2; r--) 
    {
        for (int c = col; c <= col + 1; c++) 
        {
            gameBoard[r][c] = 0;
        }
    }

    // 제거로 인해 열 col, col+1의 가장 윗블록 행 번호 갱신
    updateTopRow(col);
    updateTopRow(col + 1);

    return true;
}

/*
      - 열(col), (col+1), (col+2) 세 열을 대상으로,
        "2행 × 3열(높이2, 폭3)" 블록을 제거를 시도한다.
      - 실제 검사 범위:
         - r1 = topRowInCol[col], r2 = topRowInCol[col+1], r3 = topRowInCol[col+2]
         - maxRow = max(r1,r2,r3), minRow = min(r1,r2,r3)
         - (maxRow, maxRow-1) 행 × (col..col+2) 열
      - 조건 (문제/퍼즐별 규칙):
         1) sameMax==2 (maxRow와 같은 값이 정확히 2개),
         2) 빈 칸(0)이 정확히 2개,
         3) 나머지 칸은 모두 동일 숫자 or 0,
      - 만족하면 해당 6칸을 전부 0으로 만들고 topRowInCol 갱신, true 반환
      - 아니면 false
*/
bool removeBlock2x3(int col) 
{
    // 범위 검사: col+2가 boardSize 이상이면 3열 확보 불가
    if (col + 2 >= boardSize)
    {
        return false;
    }
    
    // 세 열 각각의 "제일 위 블록 행"
    int row1 = topRowInCol[col];
    int row2 = topRowInCol[col + 1];
    int row3 = topRowInCol[col + 2];

    int maxRow = std::max({row1, row2, row3});
    int minRow = std::min({row1, row2, row3});

    // 문제(또는 퍼즐) 로직상 sameMax==2 & 범위 체크
    int sameMaxCount = 0;
    
    if (row1 == maxRow) 
    {
        sameMaxCount++;
    }
    
    if (row2 == maxRow) 
    {
        sameMaxCount++;
    }
    
    if (row3 == maxRow)
    {
        sameMaxCount++;
    }
    
    if (sameMaxCount != 2) 
    {
        return false;
    }
    
    if (minRow < 0 || maxRow >= boardSize)
    {
        return false;
    }
    
    if (maxRow - 1 < 0) 
    {
        return false;
    }
    
    // 검사 대상 칸(2×3)의 기준값
    int val = gameBoard[maxRow][col];
    int blankCount = 0;

    // (maxRow-1..maxRow) × (col..col+2)
    for (int r = maxRow - 1; r <= maxRow; r++) 
    {
        for (int c = col; c <= col + 2; c++) 
        {
            int cell = gameBoard[r][c];
            
            if (cell != 0 && cell != val) 
            {
                return false;
            }
            
            if (cell == 0) 
            {
                blankCount++;
            }
        }
    }

    if (blankCount != 2)
    {
        return false;
    }

    // 제거 반영
    for (int r = maxRow - 1; r <= maxRow; r++)
    {
        for (int c = col; c <= col + 2; c++)
        {
            gameBoard[r][c] = 0;
        }
    }

    // 해당 열들의 topRowInCol 갱신
    updateTopRow(col);
    updateTopRow(col + 1);
    updateTopRow(col + 2);

    return true;
}

/*
     - 인자로 받은 board를 전역 gameBoard에 복사, boardSize 설정
     - 각 열별 topRowInCol를 초기화 (updateTopRow)
     - while 무한 루프:
       1) 한 바퀴 전체 열 스캔하면서
          removeBlock3x2(i) + removeBlock2x3(i) 호출
          => 성공 시 cnt++
       2) 한 라운드에서 cnt==0이면 더 이상 제거 불가 → break
       3) 제거된 개수를 answer에 누적
     - 최종 answer 반환
*/
int solution(vector<vector<int>> board) {
    // 전역 보드, 사이즈 설정
    gameBoard = board;
    boardSize = board.size();

    // 각 열의 '윗 블록 행'을 기록하는 topRowInCol 초기화
    topRowInCol.assign(boardSize, 0);
    
    for (int i = 0; i < boardSize; i++) 
    {
        updateTopRow(i);
    }

    int answer = 0;

    // 블록이 더 이상 제거되지 않을 때까지 반복
    while (true) 
    {
        int removeCount = 0;

        for (int col = 0; col < boardSize; col++) 
        {
            // 높이3×폭2 패턴 제거
            if (removeBlock3x2(col)) 
            {
                removeCount++;
            }
            
            // 높이2×폭3 패턴 제거
            if (removeBlock2x3(col))
            {
                removeCount++;
            }
        }

        if (removeCount == 0) 
        {
            // 아무것도 제거 못했다면 종료
            break;
        }
        
        answer += removeCount;
    }

    return answer;
}
