#include<stdio.h>
#include<string.h>

void sortByA(char **str,int count);
void sortByA(char **str,int count){
    int i;
    int j;
    char *temp;

    for(i = 0; i<count;i++){
	for(j = 0;j<count;j++){
	    if((strcmp(*(str+i),*(str+j))) > 0){
		temp = *(str+i);
		*(str+i) = *(str+j);
		*(str+j) = temp;
	    }
	}
    }
}

int main(void){
    char *array[] = {"aaaa","bbbb","cccc","dddd"};
    int count = sizeof(array);
    int i;

    sortByA(array,count);
    for(i = 0;i < count;i++){
	printf("%s ",array[i]);
    }
    printf("\n");
}
