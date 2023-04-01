#include <stdio.h>
#include <malloc.h>

int *fun(){
    int a[20];//动态存储分配将不会出现以下的问题

    return a;
}

int main(void){
    int *p1;

    p1 = fun();
    free(p1);
}
