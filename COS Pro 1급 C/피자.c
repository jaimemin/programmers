#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct Pizza {
    int size;
    int price;
}Pizza;

int compare_a(const void* a, const void* b) {
    Pizza first = *(Pizza*)a;
    Pizza second = *(Pizza*)b;
    if (first.size > second.size)
        return -1;
    else if (first.size < second.size)
        return 1;
    else
        return 0;
}

int compare_b(const void* a, const void* b) {
    Pizza first = *(Pizza*)a;
    Pizza second = *(Pizza*)b;
    if (first.price < second.price)
        return -1;
    else if (first.price > second.price)
        return 1;
    else
        return 0;
}

int* solution(int size[], int size_len, int price[], int price_len) {
    int* answer = (int*)malloc(sizeof(int) * 2);

    int len = size_len;
    Pizza* pizzas = (Pizza*)malloc(sizeof(Pizza) * len);

    for (int i = 0; i < len; i++) {
        pizzas[i].size = size[i];
        pizzas[i].price = price[i];
    }

    qsort(pizzas, len, sizeof(Pizza), compare_a);
    answer[0] = pizzas[0].size;

    qsort(pizzas, len, sizeof(Pizza), compare_b);
    answer[1] = pizzas[0].price;

    return answer;
}

// �Ʒ��� �׽�Ʈ���̽� ����� �غ��� ���� main �Լ��Դϴ�.
int main() {
    int size[] = { 10, 20, 30, 40 };
    int size_len = 4;
    int price[] = { 3, 1, 5, 4 };
    int price_len = 4;
    int* ret = solution(size, size_len, price, price_len);

    // [����] ��ư�� ������ ��� ���� �� �� �ֽ��ϴ�.
    printf("solution �Լ��� ��ȯ ���� {%d, %d} �Դϴ�.\n", ret[0], ret[1]);
}