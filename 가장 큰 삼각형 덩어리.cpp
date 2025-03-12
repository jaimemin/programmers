#include <string>
#include <vector>
#include <deque>
#include <array>
#include <algorithm>
using namespace std;

typedef struct
{
    int row, col;       // 격자 내 위치
    int triangleChoice; // 0: 첫 번째 삼각형, 1: 두 번째 삼각형
} TriangleBlock;

typedef struct
{
    int row, col;
} Dir;

Dir moveDir[4] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

bool isValidCell(int row, int col, int rowCount, int colCount) 
{
    return (row >= 0 && row < rowCount && col >= 0 && col < colCount);
}

/**
 * triangleCode 값
 *   1, 2: grid 값이 1 (/) 일 때의 두 삼각형 코드  
 *   3, 4: grid 값이 -1 (\) 일 때의 두 삼각형 코드
 *
 * 이동 규칙
 * - 코드 1: 좌측, 상단으로 이동  
 *     좌측: 다음 셀이 '/'이면 코드 2, '\'이면 코드 4  
 *     상단: 다음 셀이 '/'이면 코드 2, '\'이면 코드 3
 * - 코드 2: 우측, 하단으로 이동  
 *     우측: 다음 셀이 '/'이면 코드 1, '\'이면 코드 3  
 *     하단: 다음 셀이 '/'이면 코드 1, '\'이면 코드 4
 * - 코드 3: 좌측, 하단으로 이동  
 *     좌측: 다음 셀이 '/'이면 코드 2, '\'이면 코드 4  
 *     하단: 다음 셀이 '/'이면 코드 1, '\'이면 코드 4
 * - 코드 4: 우측, 상단으로 이동  
 *     우측: 다음 셀이 '/'이면 코드 1, '\'이면 코드 3  
 *     상단: 다음 셀이 '/'이면 코드 2, '\'이면 코드 3
 */
vector<array<int, 3>> getNextMoves(TriangleBlock currentBlock, 
                                   int triangleCode,
                                   vector<vector<int>> &grid, 
                                   int rowCount, 
                                   int colCount) 
{
    vector<array<int, 3>> nextMoves; // 각 원소: {다음행, 다음열, 다음 삼각형 코드}
    int curRow = currentBlock.row, curCol = currentBlock.col;
    
    if (triangleCode == 1) 
    {
        // 이동: 좌측
        int nextRow = curRow + moveDir[1].row;
        int nextCol = curCol + moveDir[1].col;
        
        if (isValidCell(nextRow, nextCol, rowCount, colCount))
        {
            int nextTriangleCode = (grid[nextRow][nextCol] == 1) ? 2 : 4;
            
            nextMoves.push_back({ nextRow, nextCol, nextTriangleCode });
        }
        
        // 이동: 상단
        nextRow = curRow + moveDir[3].row;
        nextCol = curCol + moveDir[3].col;
        
        if (isValidCell(nextRow, nextCol, rowCount, colCount)) 
        {
            int nextTriangleCode = (grid[nextRow][nextCol] == 1) ? 2 : 3;
            
            nextMoves.push_back({ nextRow, nextCol, nextTriangleCode });
        }
    } 
    else if (triangleCode == 2) 
    {
        // 이동: 우측
        int nextRow = curRow + moveDir[0].row;
        int nextCol = curCol + moveDir[0].col;
        
        if (isValidCell(nextRow, nextCol, rowCount, colCount))
        {
            int nextTriangleCode = (grid[nextRow][nextCol] == 1) ? 1 : 3;
            
            nextMoves.push_back({ nextRow, nextCol, nextTriangleCode });
        }
        
        // 이동: 하단
        nextRow = curRow + moveDir[2].row;
        nextCol = curCol + moveDir[2].col;
        
        if (isValidCell(nextRow, nextCol, rowCount, colCount)) 
        {
            int nextTriangleCode = (grid[nextRow][nextCol] == 1) ? 1 : 4;
            
            nextMoves.push_back({ nextRow, nextCol, nextTriangleCode });
        }
    }
    else if (triangleCode == 3)
    {
        // 이동: 좌측
        int nextRow = curRow + moveDir[1].row;
        int nextCol = curCol + moveDir[1].col;
        
        if (isValidCell(nextRow, nextCol, rowCount, colCount)) 
        {
            int nextTriangleCode = (grid[nextRow][nextCol] == 1) ? 2 : 4;
            
            nextMoves.push_back({ nextRow, nextCol, nextTriangleCode });
        }
        
        // 이동: 하단
        nextRow = curRow + moveDir[2].row;
        nextCol = curCol + moveDir[2].col;
        
        if (isValidCell(nextRow, nextCol, rowCount, colCount)) 
        {
            int nextTriangleCode = (grid[nextRow][nextCol] == 1) ? 1 : 4;
            
            nextMoves.push_back({ nextRow, nextCol, nextTriangleCode });
        }
    }
    else 
    {
        // 이동: 우측
        int nextRow = curRow + moveDir[0].row;
        int nextCol = curCol + moveDir[0].col;
        
        if (isValidCell(nextRow, nextCol, rowCount, colCount)) 
        {
            int nextTriangleCode = (grid[nextRow][nextCol] == 1) ? 1 : 3;
            
            nextMoves.push_back({ nextRow, nextCol, nextTriangleCode });
        }
        
        // 이동: 상단
        nextRow = curRow + moveDir[3].row;
        nextCol = curCol + moveDir[3].col;
        
        if (isValidCell(nextRow, nextCol, rowCount, colCount)) 
        {
            int nextTriangleCode = (grid[nextRow][nextCol] == 1) ? 2 : 3;
            
            nextMoves.push_back({ nextRow, nextCol, nextTriangleCode });
        }
    }
    
    return nextMoves;
}

int bfsBlobSize(int startRow, 
                int startCol, 
                int startChoice, 
                int componentId,
                vector<vector<int>> &grid,
                vector<vector<array<int, 2>>> &triangleMapping,
                vector<vector<int>> &visited, 
                int rowCount, 
                int colCount) {
    deque<TriangleBlock> queue;
    queue.push_back({ startRow, startCol, startChoice });
    visited[startRow][startCol] = componentId;
    
    int blobSize = 0;
    
    while (!queue.empty())
    {
        TriangleBlock current = queue.front();
        queue.pop_front();
        blobSize++;
        
        int currentTriangleCode = triangleMapping[current.row][current.col][current.triangleChoice];
        vector<array<int, 3>> nextMoves = getNextMoves(current, currentTriangleCode, grid, rowCount, colCount);
        
        for (const auto move : nextMoves) 
        {
            int nextRow = move[0];
            int nextCol = move[1];
            int nextTriangleCode = move[2];
            int nextChoice = (nextTriangleCode % 2 == 1) ? 0 : 1;
            
            if (!isValidCell(nextRow, nextCol, rowCount, colCount))
            {
                continue;
            }
            
            if (visited[nextRow][nextCol] == componentId)
            {
                continue;
            }
            
            visited[nextRow][nextCol] = componentId;
            queue.push_back({ nextRow, nextCol, nextChoice });
        }
    }
    
    return blobSize;
}

int solution(vector<vector<int>> grid) {
    int answer = 0;
    int rowCount = grid.size();
    
    if (rowCount == 0)
    {
        return 0;
    }
    
    int colCount = grid[0].size();
    
    // triangleMapping[r][c][0 또는 1]:
    // grid 값이 1 (/)인 경우 -> {1, 2}, grid 값이 -1 (\)인 경우 -> {3, 4}
    vector<vector<array<int, 2>>> triangleMapping(rowCount, vector<array<int, 2>>(colCount));
    vector<vector<int>> visited(rowCount, vector<int>(colCount, 0));
    
    for (int r = 0; r < rowCount; r++) 
    {
        for (int c = 0; c < colCount; c++) 
        {
            if (grid[r][c] == 1) 
            {
                triangleMapping[r][c][0] = 1;
                triangleMapping[r][c][1] = 2;
            } else 
            {
                triangleMapping[r][c][0] = 3;
                triangleMapping[r][c][1] = 4;
            }
        }
    }
    
    int componentId = 1;
    
    // 각 셀의 두 삼각형 후보에 대해, 아직 방문하지 않은 경우 BFS로 탐색
    for (int r = 0; r < rowCount; r++) 
    {
        for (int c = 0; c < colCount; c++)
        {
            for (int choice = 0; choice < 2; choice++)
            {
                if (visited[r][c] == 0)
                {
                    int blobSize = bfsBlobSize(r, c, choice, componentId, grid, triangleMapping, visited, rowCount, colCount);
                    answer = max(answer, blobSize);
                    
                    componentId++;
                }
            }
        }
    }
    
    return answer;
}
