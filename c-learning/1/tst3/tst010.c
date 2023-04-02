#include<stdio.h>

int main(void){

    //C语言中的const是一个冒牌货
    const int a = 10;
    int *p  = (int *)&a;

    *p = 20;//间接赋值
    printf("a = %d\n",a);
}
