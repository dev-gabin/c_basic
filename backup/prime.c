#include <stdio.h>
int main(int argc, char const *argv[])
{
    int count;
    int pn_count=0;
    
    printf("숫자를 입력 : ");
    scanf(" %d",&count);

    for (int i = 2; i < count; i++)
    {
        int pn=1;
        for (int j = 2; j < i; j++)
        {
            if(i%j==0){
                pn=0;
                break;
            }
            
        }
        if (pn){
            printf("%5d",i);
            pn_count++;
            if(pn_count%5==0)
                printf("\r\n");
        }


        
    }
    
    printf("\r\nfind count :%d", pn_count);
    return 0;
}
