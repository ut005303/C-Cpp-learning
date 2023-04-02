#include<stdio.h>

int str_copy(char *str1,char *str2);
int str_copy(char *str1,char *str2){

    if(str1 == NULL || str2 == NULL){
	return -1;
    }

    whille(*str2++ = *str1++);
    return 0;
}
int main(void){
    char str1[80] = "abcdefg";
    char str2[80];
    
    int ret = 0;
    ret str_copy(str1,str2);
    if(ret != 0){
	printf("有一个地址为空，所有有错\n");
    }else{
	printf("%s\n",str1);
	printf("%s\n",str2);
    }
}
