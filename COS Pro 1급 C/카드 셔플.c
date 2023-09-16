#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int n, int mix, int k) {
    int answer = 0;

    int* card = (int*)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++)
        card[i] = i + 1;

    while (mix--) {
        int* card_a = (int*)malloc(sizeof(int) * n / 2);
        int* card_b = (int*)malloc(sizeof(int) * n / 2);

        for (int i = 0; i < n; i++) {
            if (i < n / 2)
                card_a[i] = card[i];
            else
                card_b[i - n / 2] = card[i];
        }

        for (int i = 0; i < n; i++) {
            if (i % 2 == 0)
                card[i] = card_a[i / 2];
            else
                card[i] = card_b[i / 2];
        }
    }

    answer = card[k - 1];

    return answer;
}

// 아래는 테스트케이스 출력을 해보기 위한 main 함수입니다. 아래에는 잘못된 부분이 없으니 위의 코드만 수정하세요.
int main() {
    int n = 6;
    int mix = 3;
    int k = 3;
    int ret = solution(n, mix, k);

    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    printf("solution 함수의 반환 값은 %d 입니다.\n", ret);
}