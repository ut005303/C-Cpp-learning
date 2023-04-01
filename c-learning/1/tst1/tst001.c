#include<stdio.h>

void main(void)
{
    int num;
    int i;
    int n;

    printf("请输入一个数：");
    scanf("%d",&num);
    n = num;

    printf("%d = ",num);
    for(i = 2;n > 1;)
	if(n%i == 0)
	{
	    printf("%d",i);
	    if(n != i)
		printf("*");
	    n /=i;
	}
	else
	    i++;

    printf("\n");
}
