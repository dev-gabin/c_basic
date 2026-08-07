#include <stdio.h>
#include <stdlib.h>

void intput_nums(int* lotto);
void print_nums(int* lotto);


int main(int argc, char const *argv[])
{
    int lotto_nums[6];
    intput_nums(lotto_nums);
    print_nums(lotto_nums);
    return 0;
}

void input_nums(int *lotto)
{
    int num;
    int a;
    for(int i = 0; i < 6; i++)
    {
        printf("번호입력: ");
        scanf("%d", &num);
        a=0;
        // 중복검사
        for (int j = 0; j < i; j++)
        {
            if (lotto[j] == num)
            {
                a=1;
                break;
            }
        }
        if(!a){
            lotto[i] = num;
        }
        else{
            printf("같은 번호가 있습니다.\n");
            i--;
        }
    }
}

void print_nums(int *lotto)
{   
    printf("당첨번호 : ");
    for (int i = 0; i < 6; i++)
    
    {
        printf("%d", lotto[i]);

    }


    printf("\n");
       }

        