#include<stdio.h>

int main(void){
    int a = 10;
    int b = 20;
    //在C语言中，表达式的结果存放在寄存器当中，表达式返回的是变量的值
    *(a < b ? &a : &b) = 30;//C++编译器对C++语言的优化，内部就是这样实现的

    printf("a = %d,b = %d\n",a,b);

}
