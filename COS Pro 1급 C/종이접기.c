
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


// �Ʒ��� �׽�Ʈ���̽� ����� �غ��� ���� main �Լ��Դϴ�. �Ʒ����� �߸��� �κ��� ������ ���� �ڵ常 �����ϼ���.
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


    // [����] ��ư�� ������ ��� ���� �� �� �ֽ��ϴ�.
    printf("solution �Լ��� ��ȯ ���� %d �Դϴ�.\n", ret);
}