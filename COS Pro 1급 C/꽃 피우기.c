// ������ ���� include�� ����� �� �ֽ��ϴ�.
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct
{
    int y, x;
} Dir;

Dir moveDir[4] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };

bool allFilled(int** garden, int row, int col)
{
    for (int y = 0; y < row; y++)
    {
        for (int x = 0; x < col; x++)
        {
            if (garden[y][x] == 0)
            {
                return false;
            }
        }
    }

    return true;
}

int solution(int** garden, int garden_row_len, int garden_col_len) {
    // ���⿡ �ڵ带 �ۼ����ּ���.
    int answer = 0;

    int** nextGarden = (int**)malloc(sizeof(int*) * garden_row_len);

    for (int i = 0; i < garden_row_len; i++)
    {
        nextGarden[i] = (int*)malloc(sizeof(int) * garden_col_len);
    }

    for (int i = 0; i < garden_row_len; i++)
    {
        for (int j = 0; j < garden_col_len; j++)
        {
            nextGarden[i][j] = 0;
        }
    }

    while (!allFilled(garden, garden_row_len, garden_col_len))
    {
        answer++;

        for (int y = 0; y < garden_row_len; y++)
        {
            for (int x = 0; x < garden_col_len; x++)
            {
                if (garden[y][x] == 0)
                {
                    continue;
                }

                nextGarden[y][x] = 1;

                for (int k = 0; k < 4; k++)
                {
                    int nextY = y + moveDir[k].y;
                    int nextX = x + moveDir[k].x;

                    if (nextY < 0 || nextY >= garden_row_len
                        || nextX < 0 || nextX >= garden_col_len)
                    {
                        continue;
                    }

                    nextGarden[nextY][nextX] = 1;
                }
            }
        }

        for (int y = 0; y < garden_row_len; y++)
        {
            for (int x = 0; x < garden_col_len; x++)
            {
                garden[y][x] = nextGarden[y][x];
            }
        }
    }

    return answer;
}

// �Ʒ��� �׽�Ʈ���̽� ����� �غ��� ���� main �Լ��Դϴ�.
int main() {
    int garden1_row_len = 3;
    int garden1_col_len = 3;
    int** garden1 = (int**)malloc(sizeof(int*) * garden1_row_len);
    for (int i = 0; i < garden1_row_len; i++)
        garden1[i] = (int*)malloc(sizeof(int) * garden1_col_len);

    garden1[0][0] = 0;
    garden1[0][1] = 0;
    garden1[0][2] = 0;
    garden1[1][0] = 0;
    garden1[1][1] = 1;
    garden1[1][2] = 0;
    garden1[2][0] = 0;
    garden1[2][1] = 0;
    garden1[2][2] = 0;

    int ret1 = solution(garden1, garden1_row_len, garden1_col_len);

    // [����] ��ư�� ������ ��� ���� �� �� �ֽ��ϴ�.
    printf("solution �Լ��� ��ȯ ���� %d �Դϴ�.\n", ret1);

    int garden2_row_len = 2;
    int garden2_col_len = 2;
    int** garden2 = (int**)malloc(sizeof(int*) * garden2_row_len);
    for (int i = 0; i < garden2_row_len; i++)
        garden2[i] = (int*)malloc(sizeof(int) * garden2_col_len);

    garden2[0][0] = 1;
    garden2[0][1] = 1;
    garden2[1][0] = 1;
    garden2[1][1] = 1;

    int ret2 = solution(garden2, garden2_row_len, garden2_col_len);

    // [����] ��ư�� ������ ��� ���� �� �� �ֽ��ϴ�.
    printf("solution �Լ��� ��ȯ ���� %d �Դϴ�.\n", ret2);

    int garden3_row_len = 100;
    int garden3_col_len = 100;
    int** garden3 = (int**)malloc(sizeof(int*) * garden3_row_len);
    for (int i = 0; i < garden3_row_len; i++)
        garden3[i] = (int*)malloc(sizeof(int) * garden3_col_len);

    for (int y = 0; y < garden3_row_len; y++)
    {
        for (int x = 0; x < garden3_col_len; x++)
        {
            garden3[y][x] = 0;
        }
    }

    garden3[0][0] = 1;

    int ret3 = solution(garden3, garden3_row_len, garden3_col_len);

    // [����] ��ư�� ������ ��� ���� �� �� �ֽ��ϴ�.
    printf("solution �Լ��� ��ȯ ���� %d �Դϴ�.\n", ret3);
}