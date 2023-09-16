#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

int solution(int K, int numbers[], int numbers_len, char* up_down[], int up_down_len) {
    int left = 1;
    int right = K;
    for (int i = 0; i < numbers_len; i++) {
        int num = numbers[i];
        if (strcmp("UP", up_down[i]) == 0)
            left = left > (num + 1) ? left : num + 1;
        else if (strcmp("DOWN", up_down[i]) == 0)
            right = right < (num - 1) ? right : num - 1;
        else if (strcmp("RIGHT", up_down[i]) == 0)
            return 1;
    }
    return right - left + 1;
}

// 아래는 테스트케이스 출력을 해보기 위한 main 함수입니다.
int main() {
    int K1 = 10;
    int numbers1[] = { 4, 9, 6 };
    int numbers_len1 = 3;
    char* up_down1[] = { "UP", "DOWN", "UP" };
    int up_down_len1 = 3;
    int ret1 = solution(K1, numbers1, numbers_len1, up_down1, up_down_len1);

    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    printf("solution 함수의 반환 값은 %d 입니다.\n", ret1);

    int K2 = 10;
    int numbers2[] = { 2, 1, 6 };
    int numbers_len2 = 3;
    char* up_down2[] = { "UP", "UP", "DOWN" };
    int up_down_len2 = 3;
    int ret2 = solution(K2, numbers2, numbers_len2, up_down2, up_down_len2);

    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    printf("solution 함수의 반환 값은 %d 입니다.\n", ret2);

    int K3 = 100;
    int numbers3[] = { 97, 98 };
    int numbers_len3 = 2;
    char* up_down3[] = { "UP", "RIGHT" };
    int up_down_len3 = 2;
    int ret3 = solution(K3, numbers3, numbers_len3, up_down3, up_down_len3);

    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    printf("solution 함수의 반환 값은 %d 입니다.\n", ret3);
}