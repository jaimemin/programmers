#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int func_a(int stack[], int *stack_idx);
void func_b(int stack1[], int *stack1_idx, int stack2[], int *stack2_idx);
bool func_c(int stack_idx);

int func_a(int stack[], int *stack_idx) {
    int item = stack[*stack_idx];
    *stack_idx = *stack_idx - 1;
    return item;
}

void func_b(int stack1[], int *stack1_idx, int stack2[], int *stack2_idx) {
    while(!func_c(*stack1_idx)) {
        int item = func_a(stack1, stack1_idx);
        *stack2_idx = *stack2_idx + 1;
        stack2[*stack2_idx] = item;
    }
}

bool func_c(int stack_idx){
    return (stack_idx == -1);
}

int solution(int stack1[], int stack1_idx, int stack2[], int stack2_idx) {
    if(func_c(stack2_idx)){
        func_b(stack1, &stack1_idx, stack2, &stack2_idx);
    }
    int answer = func_a(stack2, &stack2_idx);
    return answer;
}

// 아래는 테스트케이스 출력을 해보기 위한 main 함수입니다.
int main() {
    int stack1_1[] = {1,2,0,0,0,0,0,0,0,0};    
    int stack1_1len = 1;
    int stack2_1[] = {3,4,0,0,0,0,0,0,0,0};
    int stack2_1len = 1;
    int ret1 = solution(stack1_1, stack1_1len, stack2_1, stack2_1len);
    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    printf("solution 함수의 반환 값은 %d 입니다.\n", ret1);

    int stack1_2[] = {1,2,3,0,0,0,0,0,0,0};    
    int stack1_2len = 2;
    int stack2_2[] = {0,0,0,0,0,0,0,0,0,0};
    int stack2_2len = -1;
    int ret2 = solution(stack1_2, stack1_2len, stack2_2, stack2_2len);
    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    printf("solution 함수의 반환 값은 %d 입니다.\n", ret2);
}
