#include <stdio.h>
#include <stdint.h>
#include <intrin.h>

int pop_count_naive(uint32_t n)
{
   int count_n=0;
    for(int i=0;i<32;i++)
    {   
        if((n & (1<<i))!=0){

            count_n++;
        }
    }
    return count_n;
}

int pop_count_kernighan(uint32_t k)
{
    int count_k=0;
    while ( k !=0)
    {
        k=k&(k-1);
        count_k++;
    }
    return count_k;
    
}

int  pop_count_swar(uint32_t s)
{
   s=s-((s>>1)&0x55555555);
   s=(s&0x33333333)+((s>>2)&0x33333333);
   s=(s&0x0F0F0F0F)+((s>>4)& 0x0F0F0F0F);
   s=(s&0x00FF00FF)+((s>>8)& 0x00FF00FF);
   s=(s&0x0000FFFF)+((s>>16)& 0x0000FFFF);

   return s;

}

int pop_count_builtin(uint32_t b)
{
    return (int)__popcnt(b);

}



int main(void)
{
    uint32_t testcases[]={0x00000000, 0x00000007, 0x12345678, 0xFFFFFFFF};
    for(int i=0;i<4;i++)
    {
        printf("Case %d : Input 0x%08X\n",i+1,testcases[i]);
        printf("[Naive]     : %d\n",pop_count_naive(testcases[i]));
        printf("[Kernighan] : %d\n",pop_count_kernighan(testcases[i]));
        printf("[SWAR]      : %d\n",pop_count_swar(testcases[i]));
        printf("[Built-in]  : %d\n",pop_count_builtin(testcases[i]));
        printf("------------------------------------\n");
        

    }

    return 0;

}