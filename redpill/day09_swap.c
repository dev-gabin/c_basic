#include <stdint.h>
#include <stdio.h>
//struct 정의
struct person
{
    char name[30];
    int id;
};



void swap_bytes(void *a, void *b, size_t size){
   uint8_t *pa=(uint8_t*)a;
   uint8_t *pb=(uint8_t*)b; 
   for(size_t i=0;i<size;i++){
    uint8_t temp= *(pa+i);
    *(pa+i)=*(pb+i);
    *(pb+i)=temp;
   }
 

}

int main(void){

    printf("=== Day 9: Generic Swap Implementation ===\n\n");
    int x=10, y=20;
    double c=3.14159, d=99.99000;
    struct person Kim = {"Kim",1};
    struct person Lee = {"Lee",2};
    
    

     //int
     printf("[Int] Before : %d, %d\n ",x,y);
     swap_bytes(&x,&y,sizeof(int));
     printf("[Int] After : %d, %d\n\n",x,y);
    
    //double
    printf("[Double] Before : %.5f, %.5f\n",c,d);
     swap_bytes(&c,&d,sizeof(double));
     printf("[Double] After : %.5f, %.5f\n\n",c,d);
    
     //struct
     printf("[Struct] Before : %s(%d), %s(%d)\n",Kim.name,Kim.id,Lee.name,Lee.id);
     swap_bytes(&Kim ,&Lee,sizeof(struct person));
     printf("[Struct] After : %s(%d), %s(%d)\n",Kim.name,Kim.id,Lee.name,Lee.id);
    
   




    return 0;


    
}
