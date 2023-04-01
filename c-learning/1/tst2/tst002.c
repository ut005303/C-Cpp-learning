#include<stdio.h>
#include<math.h>

void main(void)
{
    int n,i,j;
    printf("请输入行数（奇数）:");//因为是菱形，所以必须为奇数行
    scanf("%d",&n);

    for(i = 0; i < n; i++)
    {
	for(j = 0; j < abs(n/2 - i); j++)
	    printf(" ");
	for(j = 0; j < 2 * (n/2 - abs(n/2 -i))+1; j++)
	    printf("*");
	printf("\n");
    }
    
    printf("\n");
}
