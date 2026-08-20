#include <stdio.h>
#include <stdint.h>

// 설정: 블록 크기와 개수
#define BLOCK_SIZE  32
#define POOL_SIZE   10




typedef struct Block {
    struct Block* next;
} Block;




// 메모리 풀 컨텍스트
typedef struct {

    uint8_t memory_area[POOL_SIZE * BLOCK_SIZE]; 
    

    Block* free_list;
    

    int used_count;
} MemoryPool;

// 1. 초기화: 모든 메모리를 쪼개서 연결 리스트로 연결
void pool_init(MemoryPool* pool) {}

// 2. 할당: Free List의 헤드(Head)를 떼어줌 (Pop)
void* pool_alloc(MemoryPool* pool) {}

// 3. 해제: 반환된 블록을 Free List의 헤드에 다시 붙임 (Push)
void pool_free(MemoryPool* pool, void* ptr) {}




int main(void){

    //테스트 코드
    pool_init(&my_pool);

    // 3개 할당
    void* p1 = pool_alloc(&my_pool);
    void* p2 = pool_alloc(&my_pool);
    void* p3 = pool_alloc(&my_pool);

    printf("Allocated: %p, %p, %p\n", p1, p2, p3);
    printf("Used Blocks: %d\n", my_pool.used_count);

    // 1개 해제 (p2)
    printf("Freeing %p...\n", p2);
    pool_free(&my_pool, p2); // 이제 p2가 free_list의 head가 됨
    
    // 다시 1개 할당 (p2와 같은 주소가 나와야 함 - LIFO 특성)
    void* p4 = pool_alloc(&my_pool);
    printf("Re-allocated: %p (Should be same as old p2)\n", p4);




    //실제 코드

    

    return 0;

}