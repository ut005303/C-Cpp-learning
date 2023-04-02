#include<stdio.h>
//C++编译器是非常严格的
f(i){
    printf("%d\n",i);
}
g(){//C语言的编译器是不严格的(存在默认类型)
    return 5;
}

int main(void){
    f('A');

    printf("%d\n",g(1,2,3,4,5,6));
    return 0;
}
