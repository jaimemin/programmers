// 다음과 같이 include를 사용할 수 있습니다.
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int solution(int arr[], int arr_len, int K) {
    // 여기에 코드를 작성해주세요.
    int answer = 0;
    int* sorted = (int*)malloc(sizeof(int) * arr_len);

    for (int i = 0; i < arr_len; i++) {
        answer = (answer > arr[i]) ? answer : arr[i];

        sorted[i] = arr[i];
    }

    for (int i = 0; i < arr_len; i++) {
        for (int j = 0; j < arr_len - 1; j++)
        {
            if (sorted[j] < sorted[j + 1])
            {
                swap(&sorted[j], &sorted[j + 1]);
            }
        }
    }

    for (int i = 0; i < arr_len - (K - 1); i++)
    {
        int diff = abs(sorted[i] - sorted[i + (K - 1)]);

        answer = (answer > diff) ? diff : answer;
    }

    return answer;
}

// 아래는 테스트케이스 출력을 해보기 위한 main 함수입니다.
int main() {
    int arr[] = { 9, 11, 9, 6, 4, 19 };
    int arr_len = 6;
    int K = 4;
    int ret = solution(arr, arr_len, K);

    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    printf("solution 함수의 반환 값은 %d 입니다.\n", ret);
}