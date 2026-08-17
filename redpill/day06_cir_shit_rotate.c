#include <stdint.h>
#include<stdio.h>

void binary_f(uint32_t b)
{
    for (int i=31 ;i>=0; i--)
    {
        if(((b>>i)&1)==1)
        
            printf("1");
        else
            printf("0");

        if (i%4==0 && i !=0)
            printf(" ");
        
            
    }
    
}



uint32_t c_shift_rol(uint32_t rl,int nl)
{
   return (rl<<nl) | (rl>>32-nl);

}


uint32_t c_shift_ror(uint32_t rr,int nr)
{
   return (rr>>nr) | (rr<<32-nr);
}



int main(void){

uint32_t testcase = 0xF0000000;

printf("=== Day 6: Circular Shift (Rotate) ===\n\n");

printf("Hex : 0x%08X\n", testcase);
printf("Bin : ");
binary_f(testcase);
printf("\n\n");



uint32_t rol_result =c_shift_rol(testcase,4);
printf("[ROL 4] : ");
printf("Hex : 0x%08X\n", rol_result);
printf("Bin : ");
binary_f(rol_result);
printf("\n\n");


uint32_t ror_result =c_shift_ror(rol_result,4);
printf("[ROR 4] : ");
printf("Hex : 0x%08X\n", ror_result);
printf("Bin : ");
binary_f(ror_result);
printf("\n\n");


uint32_t testcase2=0x12345678; 
uint32_t shift_n=8;
uint32_t testcase2_result=c_shift_ror(testcase2,shift_n);

printf("Data :  0x%08X -> ROR %d  ->  0x%08X  ",testcase2,shift_n,testcase2_result);



return 0;


}












