#include <stdio.h>

int sum(int n){
    if(n==0)
        return 0;
    return n + sum(n-1);   
}
int input;

int main(int argc, char const *argv[])
{
    int input=0;
    printf("입력 : ");
    scanf("%d", &input);
    
    int result=sum(input);
    
    printf("%d",result);
    return 0;
}
