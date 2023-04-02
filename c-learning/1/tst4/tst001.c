#include<stdio.h>

int main(void){
    char str1[80] = "abcdefg";
    char str2[80];
    int i;

    for(i = 0;str1[i];i++){
	str2[i] = str1[i];
    }
    str2[i] = 0;
    printf("%s\n",str1);
    printf("%s\n",str2);

    return 0;
}
