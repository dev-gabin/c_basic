#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
bool is_little_endian();
uint32_t swap_endian(uint32_t val);

int main(int argc, char const *argv[])
{
    uint32_t network_data=0x12345678;
    printf("=== Day 2: Endianness Conversion ===\r\n");
    printf("Received Data (Hex): 0x\r\n",network_data);

    if(is_little_endian())
    {
        printf("[System Check] This system is_little_endian.\r\n");
        printf("-> Need to swap bytes to match Host Order.\r\n");
        uint32_t host_data = swap_endian(network_data);
        
        printf("Original (Network):%x\r\n",network_data);
        printf("Converted (Host):%x\r\b",host_data);


        uint8_t*ptr=(uint8_t*)&host_data;
        printf("Memory Dump: [%02x] [%02x] [%02x] [%02x] (Low Addr -> High Addr)\r\n",
            ptr[0],ptr[1],ptr[2],ptr[3]);

    }
    return 0;
}

    bool is_little_endian()
{   

    uint32_t num=0x01;
    uint8_t*first_byte=(uint8_t*)&num;
    if(first_byte[0]==1)
        return true;

    return false;

}

    uint32_t swap_endian(uint32_t val){
        return((val>>24) & 0x000000FF |
               (val>>8)  & 0x0000FF00 |
               (val<<8)  & 0x00FF0000 |
               (val<<24) & 0x00FF0000 
     
    );
    
    }


// 포인터 타입 = 몇 바이트씩 읽고 몇 바이트씩 건너뛸지를 결정하는 안경
// 엔디안을 확인하는 함수라서, num을 메모리에 저장된 바이트 배열로 다루는 게 핵심