#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

int add(int a, int b)
{
  
    return a + b;
}

int sub(int a, int b)
{
   
    return a - b;
}

int mul(int a, int b)
{
   
    return a * b;
}

int div_(int a, int b)
{
   
    return a / b;
}




//연산 번호(0~4)에 이름 붙이기, operations 배열 인덱스랑 매칭
enum
{
    ADD,
    SUB,
    MUL,
    DIV,
    EXIT,
};

int (*operations[])(int, int) = { add, sub, mul, div_ };

int main(void)
{
    printf("=== Day 11: Function Pointer Array Calculator ===\n\n");

		int choice, a, b;
        printf("Select (0:Add, 1:Sub, 2:Mul, 3:Div, 4:Exit): ");
        
        while (scanf("%d", &choice) == 1 && choice != EXIT)
        {
            printf("Input two integers: ");
            scanf("%d %d", &a, &b);
            printf(">> Result: %d\n\n", operations[choice](a,b));
            printf("Select (0:Add, 1:Sub, 2:Mul, 3:Div, 4:Exit): ");
    }

    return 0;
}