#include<stdio.h>

typedef int* TYPE;

int main(void){
    //TYPE const a
    const TYPE a;
    int b = 10;
    int c = 20;

    a = &b;
    a = &c;

    return 0;
}
