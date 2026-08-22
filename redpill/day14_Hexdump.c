#include <stdio.h>
#include <stdint.h>

typedef struct {
    uint32_t id;
    char name[9];
    float value;
} SensorData;

void hexdump(const char *label, void *addr, int len)
{
    uint8_t *p = (uint8_t*)addr; // 주소를 uint8_t로 캐스팅

    printf("%s:\n", label);

    for (int i = 0; i < len; i += 16)   // 16바이트씩 한 줄
    {
        printf("  %04X  ", i);   // 오프셋 출력

        // hex 값 출력
        for (int j = 0; j < 16; j++)
        {
            if (i + j < len)
                printf("%02x ", p[i+j]);
            else
                printf("   ");   // 데이터 없는 자리는 빈칸으로 정렬
        }

        printf(" ");

        // ASCII 표현 출력 (32(공백) ~ 126(~) 사이 -> 사람이 읽을 수 있는 문자!
        for (int j = 0; j < 16; j++)
        {
            if (i + j < len)
            {
                if (p[i+j] <= 32 || p[i+j] >= 126)
                    printf(".");
                else
                    printf("%c", p[i+j]);
            }
        }

        printf("\n");
    }
}

int main(void)
{
    // 테스트 1: 단순 문자열
    char my_text[] = "Hello Embedded World! This is Hexdump.";
    hexdump("String Dump", my_text, sizeof(my_text));

    printf("\n");

    // 테스트 2: 구조체 (엔디안 확인 가능)
    SensorData sensor = { 0x12345678, "Sensor A", 3.14f };
    hexdump("Struct Dump", &sensor, sizeof(sensor));

    return 0;
}