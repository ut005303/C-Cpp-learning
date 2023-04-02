#include<stdio.h>
#include<string.h>

void strstrCount(char *p,char *q,int *count);

void strstrCount(char *p,char *q,int *count){

    int c = 0;
    if(p == NULL || q == NULL){
	printf("有地址为空，不能查找子串个数\n");
	return;
    }
    while(p = strstr(p,q)){
	c++;
	p = p + strlen(q);
	if(p == NULL){
	    break;
	}
    }

    *count = c;
}
int main(void){
    char *p = "abc123456abc3244abc44545abc";
    char *q = "abc";
    int count = 0;

    strstrCount(p,q,&count);
    printf("%d\n",count);

    return 0;
}
