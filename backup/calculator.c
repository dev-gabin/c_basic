#include <stdio.h>
// 4칙연산 4 + 5,  scanhf

int main(void)
{
    int a, b;
    char op;
    printf("integer : ");
    scanf("%d %c %d", &a, &op, &b);

    switch(op){
        case '+' :
            printf("%d %c %d=%f\r\n", a, op, b, (float)a + b); 
            break;
           
        case '-':
            printf("%d %c %d=%d\r\n",a, op, b, a  - b);
            break;
        case '*':
             printf("%d %c %d=%d\r\n",a, op, b, a  * b);
            break;
        case '/':
            if(b==0){
                printf("no divide by %d",b);
                return 0; }
            printf("%d %c %d=%f\r\n", a, op, b, (float)a / b);
            break;

        

    }



//     if ('*' == op)
//         printf("%d %c %d=%d", a, op, b, a * b);
//     else if (op == '+')
//         printf("%d %c %d=%d", a, op, b, a + b);
//     else if (op == '-')
//         printf("%d %c %d=%d", a, op, b, a - b);
//         else if (op == '/'){
//         if(b==0)
//             printf("no divide by %d",b);
//             return 0;  
//         printf("%d %c %d=%d", a, op, b, a / b);
//     }
            
//     return 0;
// 
}
