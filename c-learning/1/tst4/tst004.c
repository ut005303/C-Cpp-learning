#include<stdio.h>
#include<string.h>
#include<malloc.h>

void trimSpace(char **str1,char *str2);
void trimSpace(char **str1,char *str2){
    int length = strlen(str2);
    char *tmp;

    *str1 = (char *)malloc(sizeof(char)*length);
    tmp = *str1;

    for(;*str2;str2++){
	if(*str2 != ' '){
	    *tmp++ = *str2;
	}
    }
    *tmp = 0;
}

int main(void){
    char str[] = "       abcdefg         ";
    char *str1;
    
    printf("%s\n",str);
    trimSpace(&str1,str);
    printf("%s\n",str1);
}
