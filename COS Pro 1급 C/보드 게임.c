#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>


#define MAX(a, b) ((a) > (b) ? (a) : (b))


int solution(int** board, int board_row_len, int board_col_len) {
    int answer = 0;

    int coins[4][4] = { 0, };
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (i == 0 && j == 0)
                coins[i][j] = board[i][j];
            else if (i == 0 && j != 0)
                coins[i][j] = board[i][j] + coins[i][j - 1];
            else if (i != 0 && j == 0)
                coins[i][j] = board[i][j] + coins[i - 1][j];
            else
                coins[i][j] = board[i][j] + MAX(coins[i - 1][j], coins[i][j - 1]);
        }
    }

    answer = coins[3][3];
    return answer;
}


// 아래는 테스트케이스 출력을 해보기 위한 main 함수입니다. 아래에는 잘못된 부분이 없으니 위의 코드만 수정하세요.
int main() {
    int board_row_len = 4;
    int board_col_len = 4;
    int** board = (int**)malloc(sizeof(int*) * board_row_len);
    for (int i = 0; i < board_row_len; i++)
        board[i] = (int*)malloc(sizeof(int) * board_col_len);

    board[0][0] = 6; board[0][1] = 7;
    board[0][2] = 1; board[0][3] = 2;
    board[1][0] = 3; board[1][1] = 5;
    board[1][2] = 3; board[1][3] = 9;
    board[2][0] = 6; board[2][1] = 4;
    board[2][2] = 5; board[2][3] = 2;
    board[3][0] = 7; board[3][1] = 3;
    board[3][2] = 2; board[3][3] = 6;

    int ret = solution(board, board_row_len, board_col_len);


    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    printf("solution 함수의 반환 값은 %d 입니다.\n", ret);
}