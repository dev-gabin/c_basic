#include <stdio.h>  
#include "include/hello.h"
int x=0;


int main(int a, int b){
    int c=100; 
    char gg='d';
    char d='a';
    char e[]="abcde";
    float f=1.0;
    double g=1.0;
    
    printf("hello world\r\n");
   
    printf("result %d\r\n",y(2));
    //y=x*2;

    return 0;
}

int y(int x){
    return x*2;
} 