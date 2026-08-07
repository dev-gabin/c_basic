#include <stdio.h>

long long sum(int n){
    long long result=0;
    

    while (1);
    {
        result = result;
       
    }
    

    
    for (size_t i = 1; i <= n; i++)
    {
       result = result + i;
    }
    return result;
    
}
int input;

int main(int argc, char const *argv[])
{
    int input=1000000000000;
    printf("입력 : ");


    //scanf("%d", &input);

    long long  result=sum(input);
    printf("%I64d",result);
    return 0;
}


