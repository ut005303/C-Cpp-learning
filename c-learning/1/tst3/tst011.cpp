#include<stdio.h>
#include<iostream>

using namespace std;

int main(void){
    const int a = 10;//符号表，键值对的存储
    int *p = (int *)&a;//此时另外分配了内存空间，时机；编译器在编译期间

    //C++语言中const 是一个真正的常量
    *p = 20;
    printf("a = %d\n",a);
}
