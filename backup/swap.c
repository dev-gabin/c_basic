#include <stdio.h>
void swap(void *a, void *b){

    printf("a: %d, b: %d\n",*(int*)a,*(int*)b);

    int temp=*(int*)a;
    *(int*)a=*(int*)b;
    *(int*)b=temp;
}
int main(int argc, char const *argv[])
{
    int a=1,b=2;

    swap(&a,&b);

    printf("a: %d, b: %d",a,b);
    return 0;
}


// char은 1byte, int는 4byte이므로 a와 b의 값이 바뀌지 않는다.