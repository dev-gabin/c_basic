#include <stdio.h>
#include <stddef.h>// 표준 offsetof(비교용)

//My Macro
#define my_offset(type, member) ((size_t) &(((type*)0)->member))

typedef struct Sample {
    char a;
    // (padding 3 bytes) - 4바이트 정렬을 위해 컴파일러가 넣음
    int b;
    double c;
} Sample;

int main(void){
    printf("=== Day 12: offsetof Implementation ===\n\n");
    printf("Struct Size: %zu bytes\n\n", sizeof(Sample));
    printf("[Standard] Offset of a: %zu\n", offsetof(Sample, a));
    printf("[Standard] Offset of b: %zu\n", offsetof(Sample, b));
    printf("[Standard] Offset of c: %zu\n\n", offsetof(Sample, c));

    printf("-----------------------------\n\n");

    printf("[My Macro] Offset of a: %zu\n", my_offset(Sample, a));
    printf("[My Macro] Offset of b: %zu\n", my_offset(Sample, b));
    printf("[My Macro] Offset of c: %zu\n\n", my_offset(Sample, c));

    if (offsetof(Sample, a) == my_offset(Sample, a) &&
        offsetof(Sample, b) == my_offset(Sample, b) &&
        offsetof(Sample, c) == my_offset(Sample, c))
    {
        printf(">> Success! Implementation is correct.\n");
    }

    return 0;

}