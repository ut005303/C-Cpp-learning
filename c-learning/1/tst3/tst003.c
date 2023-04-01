#include<stdio.h>

void fun (int *);
void fun (int *num){
    *num = 5;//通过指针修改a空间的值，进行了指向运算
}

int main(void)
{
    int a = 6;
    fun(&a);//传的是a空间的地址
    printf("%d\n",a);//输出结果是5
}
