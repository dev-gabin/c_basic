#include <stdint.h>
#include <stdio.h>
#include <stddef.h>

uint8_t *overlap_memmove(uint8_t *dest,const uint8_t *src, size_t len)
{   
    if (len == 0) return dest;  //underflow 방지 
    if(dest>src){
        for(int i=len-1;i>=0;i--)
         *(dest+i) = *(src+i);
    }
    else{
        for(int i=0;i<len;i++)
          *(dest+i) = *(src+i);
     

    }
    return dest;
}




int main(void){

printf("=== Day 8: Safe Memcpy (memmove) Implementation ===\n\n");


uint8_t init[] = {0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0A};
uint8_t backup[] = {0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0A};


/**Test 1 **/
printf("[Initial] ");
for(int i=0; i<10;i++){
    printf("%02X",*(init+i));
    if (i!=9)
     printf(" ");     
}
    printf("\n\n");


printf("Test 1: Overlap (Dest > Src) -> Shift Right 2 bytes\n");
printf("[Result ] ");

overlap_memmove(&init[2],&init[0],5);
    for(int i=0; i<10;i++){

        printf("%02X",*(init+i));
        if (i!=9)
        printf(" ");  
    }
        printf("\n");
        printf(">> Success!\n\n\n");


/**Test 2 **/

printf("[Initial] ");
for(int i=0; i<10;i++){
    printf("%02X",*(backup+i));
    if (i!=9)
    printf(" ");     
}
printf("\n\n");

printf("Test 2: Overlap (Dest < Src) -> Shift Left 2 bytes\n");
printf("[Result] ");
overlap_memmove(&backup[0],&backup[2],5);
    for(int i=0; i<10;i++){

        printf("%02X",*(backup+i));
        if (i!=9)
        printf(" ");  
    }
        printf("\n");
        printf(">> Success!\n");

    return 0;



}