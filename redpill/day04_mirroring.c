#include <stdio.h>
#include <stdint.h>

uint8_t revers_bits(uint8_t input){
    uint8_t output =0;

    for (int i=0;i<8;i++){
        uint8_t bit=(input>>i) & 1;
        output |=(bit<<(7-i));

    }

    return output;
}

void p_binary8(uint8_t value)
{
    for(int i=7;i>=0;i--)
    {
        printf("%d",(value>>i) & 1);

        if(i==4)
        {
            printf(" ");
        }

    }
}

int main(void)
{
    uint8_t number[4] = {0xD2, 0x0F, 0xAA, 0x12};
    uint8_t expected[4] = {0x4B, 0xF0, 0x55, 0x48};

    
    printf("=== Day 4: Bitwise Reverse (Mirroring) ===\n\n");
    for(int i = 0; i<4;i++)
    {   
        uint8_t result =revers_bits(number[i]);

        printf("Case %d:\n", i + 1);
        
        printf("  Input : 0x%02X (", number[i]);
        p_binary8(number[i]);
        printf(")\n");
        
        printf("  Output: 0x%02X (", result);
        p_binary8(result);
        printf(")\n");

        printf("  Verify: %s\n", (result == expected[i]) ? "OK" : "FAIL");
        printf("----------------------------\n");
    }

    return 0;
}
    

