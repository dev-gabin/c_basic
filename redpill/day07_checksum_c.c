#include <stdio.h>
#include <stdint.h>

uint8_t checksum_cal(uint8_t *data , int len){
    uint8_t checksum=0;
    for(int i=0;i<len;i++){
        checksum^=*data;
        data++;
    }
    return checksum;

}




int main(void){

    printf("=== Day 7: XOR Checksum Calculation ===\n\n");
    
    uint8_t send_data []= {0x01, 0x04, 0x10, 0x20, 0x30, 0x40};
    uint8_t *p=send_data;  // 배열 이름은 이동할 수 없으므로 포인터에 시작 주소를 저장
   
    
    //** Sending packet **//
    int send_len = sizeof(send_data) / sizeof(send_data[0]);
    printf("[TX] Sending Packet...\n");
    printf("     Data: ");
        for (int i=0;i<send_len;i++){
            printf("0x%02X",*p); 

            if(i != send_len -1)
                printf(" ");
            p++;    
        }
    printf("\n");
    uint8_t checksum = checksum_cal(send_data, send_len);
    printf("     Calculated Checksum : 0x%02X\n\n", checksum);



    //** Receiving Normal Packet **//
    uint8_t normal_packet[] = {0x01, 0x04, 0x10, 0x20, 0x30, 0x40, checksum};
    //원본 데이터+체크섬데이터
    int normal_len = sizeof(normal_packet) / sizeof(normal_packet[0]);
    printf("[RX] Receiving Normal Packet...\n");
    printf("     >> Verification SUCCESS (Result:0x%02X)\n\n",checksum_cal(normal_packet,normal_len));
    
    
    

    //** Receiving Corrupted Packet **//
    uint8_t corrupt_packet []={0x01, 0x04, 0xEF, 0x20, 0x30, 0x40, checksum};
    uint8_t *np=corrupt_packet;
    
    int corrupt_len = sizeof(corrupt_packet) / sizeof(corrupt_packet[0]);
    printf("[RX] Receiving Corrupted Packet (Noise injected)...\n");
    printf("     Corrupted Data: ");
        for(int i=0;i<corrupt_len;i++){
            printf("0x%02X",*np);

            if(i != corrupt_len -1)
                printf(" ");
            np++;  
        }
        printf("\n");
        printf("     >> Verification FAIL (Result: 0x%02X)\n",checksum_cal(corrupt_packet,corrupt_len));
        printf("     >> Error detected! Discarding packet.\n");



        
    
        return 0;
    } 
        




