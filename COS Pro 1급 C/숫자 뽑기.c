// ������ ���� include�� ����� �� �ֽ��ϴ�.
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
    // ���⿡ �ڵ带 �ۼ����ּ���.
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

// �Ʒ��� �׽�Ʈ���̽� ����� �غ��� ���� main �Լ��Դϴ�.
int main() {
    int arr[] = { 9, 11, 9, 6, 4, 19 };
    int arr_len = 6;
    int K = 4;
    int ret = solution(arr, arr_len, K);

    // [����] ��ư�� ������ ��� ���� �� �� �ֽ��ϴ�.
    printf("solution �Լ��� ��ȯ ���� %d �Դϴ�.\n", ret);
}