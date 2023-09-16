#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define INC 0
#define DEC 1

int* func_a(int arr[], int arr_len) {
    int* ret = (int*)malloc(sizeof(int) * arr_len);
    ret[0] = 1;
    for (int i = 1; i < arr_len; i++) {
        if (arr[i] != arr[i - 1])
            ret[i] = ret[i - 1] + 1;
        else
            ret[i] = 2;
    }
    return ret;
}

int* func_b(int arr[], int arr_len) {
    int* ret = (int*)malloc(sizeof(int) * arr_len);
    ret[0] = -1;
    for (int i = 1; i < arr_len; i++) {
        if (arr[i] > arr[i - 1])
            ret[i] = INC;
        else if (arr[i] < arr[i - 1])
            ret[i] = DEC;
    }
    return ret;
}

int func_c(int arr[], int arr_len) {
    int ret = 0;
    for (int i = 0; i < arr_len; i++)
        if (ret < arr[i])
            ret = arr[i];
    if (ret == 2)
        return 0;
    return ret;
}

int solution(int S[], int S_len) {
    int* check = func_b(S, S_len);
    int* dp = func_a(check, S_len);
    int answer = func_c(dp, S_len);
    return answer;
}

// �Ʒ��� �׽�Ʈ���̽� ����� �غ��� ���� main �Լ��Դϴ�.
int main() {
    int S1[] = { 2, 5, 7, 3, 4, 6, 1, 8, 9 };
    int S1_len = 9;
    int ret1 = solution(S1, S1_len);

    // [����] ��ư�� ������ ��� ���� �� �� �ֽ��ϴ�.
    printf("solution �Լ��� ��ȯ ���� %d �Դϴ�.\n", ret1);

    int S2[] = { 4, 3, 2, 1, 10, 6, 9, 7, 8 };
    int S2_len = 9;
    int ret2 = solution(S2, S2_len);

    // [����] ��ư�� ������ ��� ���� �� �� �ֽ��ϴ�.
    printf("solution �Լ��� ��ȯ ���� %d �Դϴ�.\n", ret2);

    int S3[] = { 1, 2, 3, 4, 5 };
    int S3_len = 5;
    int ret3 = solution(S3, S3_len);

    // [����] ��ư�� ������ ��� ���� �� �� �ֽ��ϴ�.
    printf("solution �Լ��� ��ȯ ���� %d �Դϴ�.\n", ret3);
}