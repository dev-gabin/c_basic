#include <stdint.h> //정수 타입 관련
#include <stdio.h> //입출력 함수 관련

#define BIT_SET(var,pos)        ((var) |=  (1UL<<(pos)))
#define BIT_CLEAR(var,pos)      ((var) &= ~(1UL<<(pos)))
#define BIT_TOGGLE(var,pos)     ((var) ^=  (1UL<<(pos)))
#define BIT_CHECK(var,pos)     ((var) &  (1UL<<(pos)))>>(pos)
int main(int argc, char const *argv[])
{
    uint32_t hex = 0x12345678;  //0x5 0101  0xA 1010 0XF 1111
  
    int pos;
    
    printf("[init] Hex: 0x%X\n\n",hex);

    pos=0;
    hex=BIT_SET(hex,pos);
    printf("[SET] Target: Bit %d\n",pos);
    printf("Result Hex: 0x%X\n\n",hex);
    
    pos=4;
    hex=BIT_CLEAR(hex,pos);
    printf("[CLEAR] Target: Bit %d\n",pos);
    printf("Result Hex: 0x%X\n\n",hex);
    
    pos=3;
    hex=BIT_TOGGLE(hex,pos);
    printf("[TOGGLE] Target: Bit %d\n",pos);
    printf("Result Hex: 0x%X\n\n",hex);
    
    pos=3;
    hex=BIT_CHECK(hex,pos);
    printf("[CHECK] Bit %d is currently:",pos);

    return 0;
}
