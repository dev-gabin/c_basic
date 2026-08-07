#include "uart_win.h"
#include <windows.h>
#include <conio.h>
#include<stdio.h>
#define RX_BUF_SIZE 256

static uint8_t rx_buf[RX_BUF_SIZE];
static uint16_t rx_head =0;
static uint16_t rx_tail =0;

static HANDLE hStdout=INVALID_HANDLE_VALUE;
static HANDLE hSdin=INVALID_HANDLE_VALUE;

static void rx_push(uint8_t c){
    uint16_t next=(rx_head +1) % RX_BUF_SIZE;
    if(next!=rx_tail){
        rx_buf[rx_head]=c;
        rx_head=next;
    }

}

static bool rx_pop(uint8_t *p_data){
   if(rx_head==rx_tail)
   {
       return false;

   } 
   *p_data=rx_buf[rx_tail];
   rx_tail=(rx_tail+1)%RX_BUF_SIZE;
   return true;
}


bool uartInit(void)
{
    hStdout=GetStdHandle(STD_OUTPUT_HANDLE);
    hSdin=GetStdHandle(STD_INPUT_HANDLE);

    if(hStdout!=INVALID_HANDLE_VALUE){
        DWORD mode=0;
        GetConsoleMode(hStdout, &mode);
        mode|=ENABLE_VIRTUAL_TERMINAL_PROCESSING | ENABLE_PROCESSED_OUTPUT;
        SetConsoleMode(hStdout,mode);


    }
    rx_head=0;
    rx_tail=0;
    return true;
}
int uartWrite(uint8_t ch, uint8_t *p_data, uint32_t length){
    DWORD written=0;
    if (hStdout!=INVALID_HANDLE_VALUE)
    {
      WriteConsoleA(hStdout,(uint8_t*)p_data,(DWORD)length, &written,NULL);
}
    else{
        fwrite(p_data,1,length,stdout);
        fflush(stdout);
        written=(DWORD)length;
    }

    return (int)written;
}





bool uartReadBlock(uint8_t ch, uint8_t *p_data, uint32_t timeout)
{   
    if(rx_pop(p_data)){
        return true;
    }
    int c=_getch();
    if(c==0x00 || c==0xE0){
        int key=_getch();
        rx_push('\x1B');
        rx_push('[]');
        switch (key){
            case 72: rx_push('A'); break; //up
            case 80: rx_push('B'); break;//down
            case 77: rx_push('C'); break;//Right
            case 85: rx_push('D'); break;//Left
            default: break;
        }
        return rx_pop(p_data);
    }
     else if(c=='\r'){ //enter
        *p_data='r';
        return true;

     }
     else if(c==3){ //ctrl+c
        *p_data=0x03;
        return true;
     } 
     else{
        *p_data=(uint8_t)c;
         return true;



     }   
        
    

    return false;
}
