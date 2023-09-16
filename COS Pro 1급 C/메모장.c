// ������ ���� include�� ����� �� �ֽ��ϴ�.
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int K, char* words[], int words_len) {
    // ���⿡ �ڵ带 �ۼ����ּ���.
    int answer = 1;
    int maxLen = strlen(words[0]);

    for (int i = 1; i < words_len; i++)
    {
        int len = strlen(words[i]);

        if (maxLen != 0 && maxLen + (len + 1) <= K)
        {
            maxLen += (len + 1);
        }
        else if (maxLen != 0 && maxLen + (len + 1) > K)
        {
            answer++;

            maxLen = len;
        }
    }

    return answer;
}

// �Ʒ��� �׽�Ʈ���̽� ����� �غ��� ���� main �Լ��Դϴ�.
int main() {
    int K = 10;
    char* words[] = { "nice", "happy", "hello", "world", "hi" };
    int words_len = 5;
    int ret = solution(K, words, words_len);

    // [����] ��ư�� ������ ��� ���� �� �� �ֽ��ϴ�.
    printf("solution �Լ��� ��ȯ ���� %d �Դϴ�.\n", ret);
}