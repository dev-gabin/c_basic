#include <stdio.h>
#include <stdint.h>

#define BUF_SIZE 8


typedef struct {
    uint8_t buffer[BUF_SIZE];   // 실제 데이터를 담을 배열
    int head;                    // Put 위치
    int tail;                    // Get 위치
} RingBuffer;



void rb_init(RingBuffer *rb){
    rb->head =0;
    rb->tail=0;
    
    
}

//push 요청
int rb_put(RingBuffer *rb, uint8_t data){

    int next_head= (rb->head +1) % BUF_SIZE;  //다음 head 위치 (0으로 순환)

    
    if(next_head == rb->tail){
        return 0;  //FULL!(overflow 방지 로직)
    }
    
    rb->buffer[rb->head] =data;
    rb->head=next_head;
    return 1; 

    
}

//pop 요청
int rb_get(RingBuffer *rb, uint8_t *data){

    if (rb->head == rb->tail)
    {
        return 0;   // Empty!(overflow 방지 로직)
    }
    
    *data = rb->buffer[rb->tail];
    rb->tail = (rb->tail + 1) % BUF_SIZE;   // tail을 다음 자리로
    return 1; 


}







// ---- 테스트 코드 ----
int main() {
    RingBuffer uart_rx_buf;
    uint8_t temp;

    rb_init(&uart_rx_buf);

    printf("--- Phase 1: Filling Buffer ---\n");
    // 버퍼 사이즈가 8이므로, 한 칸 비우면 최대 7개 저장 가능
    for (int i = 1; i <= 8; i++) {
        if (rb_put(&uart_rx_buf, i)) {
            printf("Put: %d (Head: %d, Tail: %d)\n", i, uart_rx_buf.head, uart_rx_buf.tail);
        } else {
            printf("Fail to Put: %d (Buffer Full!)\n", i);
        }
    }

    printf("\n--- Phase 2: Reading Buffer ---\n");
    // 3개만 읽어봄
    for (int i = 0; i < 3; i++) {
        if (rb_get(&uart_rx_buf, &temp)) {
            printf("Get: %d (Head: %d, Tail: %d)\n", temp, uart_rx_buf.head, uart_rx_buf.tail);
        }
    }

    printf("\n--- Phase 3: Writing again (Wrap around) ---\n");
    // 읽어서 공간이 생겼으므로 다시 쓰기 가능 (인덱스가 0으로 돌아가는지 확인)
    if (rb_put(&uart_rx_buf, 99)) {
         printf("Put: 99 (Head: %d, Tail: %d)\n", uart_rx_buf.head, uart_rx_buf.tail);
    }

    return 0;
}