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

// �Ʒ��� �׽�Ʈ���̽� ����� �غ��� ���� main �Լ��Դϴ�. �Ʒ����� �߸��� �κ��� ������ ���� �ڵ常 �����ϼ���.
int main() {
    int n = 6;
    int mix = 3;
    int k = 3;
    int ret = solution(n, mix, k);

    // [����] ��ư�� ������ ��� ���� �� �� �ֽ��ϴ�.
    printf("solution �Լ��� ��ȯ ���� %d �Դϴ�.\n", ret);
}