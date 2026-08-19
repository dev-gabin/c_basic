#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

int add(int a, int b)
{
    printf("Input two integers: ");
    scanf("%d %d", &a, &b);
    return a + b;
}

int sub(int a, int b)
{
    printf("Input two integers: ");
    scanf("%d %d", &a, &b);
    return a - b;
}

int mul(int a, int b)
{
    printf("Input two integers: ");
    scanf("%d %d", &a, &b);
    return a * b;
}

int div_(int a, int b)
{
    printf("Input two integers: ");
    scanf("%d %d", &a, &b);
    return a / b;
}



int do_exit(int a, int b)
{
    exit(0);//함수 즉시 종료
    return 0;
}




enum
{
    ADD,
    SUB,
    MUL,
    DIV,
    EXIT,
};

int (*operations[])(int, int) = { add, sub, mul, div_, do_exit };

int main(void)
{
    printf("=== Day 11: Function Pointer Array Calculator ===\n\n");

    int choice;  //연산 번호를 담을 변수

    while (1)
    {
        printf("Select (0:Add, 1:Sub, 2:Mul, 3:Div, 4:Exit): ");
        scanf("%d", &choice);

        printf(">> Result: %d\n\n", operations[choice](0, 0));
    }

    return 0;
}