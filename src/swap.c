#include <stdio.h>
void swap(void *a, void *b){
    // int teamp= *a;
    // *a=*b;
    // *b=teamp;
}
int main(int argc, char const *argv[])
{
    int a=1,b=2;

    swap(&a,&b);

    printf("a: %d, b: %d",a,b);
    return 0;
}


