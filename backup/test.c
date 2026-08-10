#include <stdio.h>
void swap(float *a, float *b){
    float temp=*a;
    *a=*b;
    *b=temp;
}

int main(void){
   float a,b,c;
   printf("실수 3개 입력\r\n");
   scanf("%f %f %f", &a, &b, &c);

   if(b>c) swap(&b,&c);
   if(a<b) swap(&a,&b);
   if(b<c) swap(&b,&c);


      printf("실수 3개 출력 : %f,%f,%f",a,b,c);
      return 0;

}