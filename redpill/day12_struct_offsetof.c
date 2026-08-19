#include <stdio.h>
#include <stdint.h>


#define my_offset(type, member) ((size_t) &(((type*)0)->member))



typedef struct {
    char a;      
    // (padding 3 bytes) - 4바이트 정렬을 위해 컴파일러가 넣음
    int b;       
    double c;    
} Sample;





int main(void){
    printf("=== Day 12: offsetof Implementation ===\n\n");
    printf("Struct Size: %zu bytes",sizeof(Sample));
    printf("\n\n");
    
}