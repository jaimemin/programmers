
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>


int max(int a, int b) {
    return a < b ? b : a;
}


int solution(int** grid, int grid_row_len, int grid_col_len) {
    int answer = 0;
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            for (int k = j + 1; k < 4; k += 2)
                answer = max(answer, max(grid[i][j] + grid[j][k], grid[j][i] + grid[k][i]));
    return answer;
}


// 아래는 테스트케이스 출력을 해보기 위한 main 함수입니다. 아래에는 잘못된 부분이 없으니 위의 코드만 수정하세요.
int main() {
    int grid_row_len = 4;
    int grid_col_len = 4;
    int** grid = (int**)malloc(sizeof(int*) * grid_row_len);
    for (int i = 0; i < grid_row_len; i++) {
        grid[i] = (int*)malloc(sizeof(int) * grid_col_len);
    }

    grid[0][0] = 1; grid[0][1] = 4;
    grid[0][2] = 16; grid[0][3] = 1;
    grid[1][0] = 20; grid[1][1] = 5;
    grid[1][2] = 15; grid[1][3] = 8;
    grid[2][0] = 6; grid[2][1] = 13;
    grid[2][2] = 36; grid[2][3] = 14;
    grid[3][0] = 20; grid[3][1] = 7;
    grid[3][2] = 19; grid[3][3] = 15;

    int ret = solution(grid, grid_row_len, grid_col_len);


    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    printf("solution 함수의 반환 값은 %d 입니다.\n", ret);
}