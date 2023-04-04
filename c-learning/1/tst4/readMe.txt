案例：char *str1 = "hello world"和char str2[] = "hello world";
============内存管理============
内存总共分为了：只读代码段、只读数据段、BSS、堆、栈五个不同的区域
1、只读代码段放的是常量(字符串常量，数组名称，函数名称)，只读区域不能更改
2、BSS区域存放的是全局变量和static静态类变量，又分为未初始化，值都为0和已初始化;
3、堆中存放的是malloc()，calloc()....申请的空间，不由操作系统回收，必须靠程序员自己通过free()回收空间，不然就是内存泄露了。
4、栈中存放的是局部变量，形参变量，栈中空间可以被任何函数所使用，数据的可靠性比较低；
==============指针变量=================
指针变量允许加减整型，例如str1++=>right,结果还是指针
字符数组不允许加减整型,str2++=>false,常量不能被赋值。
"hello world"字符串本身就是以0结尾的字符数组。
"hello world"字符串常量在只读数据段，值本身内容不能被修改。
    str1为指针变量，*str1 = 't' => false; 更改的是只读数据段中的区域;
    str2为数组名称，其空间在栈中申请，*str2 = 't' =>true，栈中的数据可以被更改。
================对指针变量的深刻理解==================    
strlen(str1)=>11
strlen(str2)=>11
sizeof(str2)=>12;数组名称，求字节数，是数组所申请空间的字节数，在0结束
sizeof(str1)=>4/8与平台有关，32位系统下，指针4个字节，64位下指针8个字节；
sizeof(*str1) 1 *str1就是'h',占用一个字节
sizeof('hello world');12字符串常量所占空间;

strlen()求的是字符串长度，不算那个0;sizeof();关键字，单目运算符，求字节数，算字符串的字节数结束标志0，这就是区别。数组[]中的值，由初值个数决定。
=====================strlen()_strcmp()_const简介=======================
在C语言中，对于基础库函数的实现是非常重要的，很考验一个人的基本功，今天主要写的是strlen()、strcmp()这两个常用函数的实现
1、strlen()函数的实现 ========>主要计算字符串的长度
#include<stdio.h>

int strLen(char *str);
int strLen(char *str){
    int i = 0;
    while(*str){
	str++;
	i++;
    }
    return i;
}
void main(void){
    char *str = "abcdefg";
    int length;

    length = strLen(str);
    printf("%d\n",length);
}
2、strcmp实现比较两个字符串是否相同
#include<stdio.h>
int strCmp(char *str1,char *str2);

int strCmp(char *str1,char *str2){
    while(*str1 == *str2 && *str1 && *str2){
	str1++;
	str2++;
    }
    return *str1 - *str2;
}
void main(void){
    char *str1 = "hello";
    char *str2 = "hell";

    printf("%d\n",strCmp(str1,str2));
}
==================三、const的用法=========================
在C语言中，const是只读。
const int a = 100 <==> int const a = 100;a空间是只读空间，a空间的值不能更改;
const int *a; <==> int const *a;*a的值不能改变，a指针变量的值可以更改;
int * const a;*a的值可以更改，a指针变量只读，不能改其值
const int * const a;*a,a均只读空间，其值不可更改;
const 离谁近，修饰谁，谁就不可更改。
==================四、C语言中内存对齐与结构体===============
结构体是一种新的数据类型，对C语言的数据类型进行了极大的扩充。
struct STU{
    int age;
    char name[15];
};

struct STU a;//结构体实例
struct STU *b;//结构体指针

1、可以通过a.age对其进行取成员的操作，b->age也可以进行结构体的操作，b->age存在问题，必须有一个结构体空间已经让b指向，b的值为此结构体空间的地址。
2、a.name = "lilei";=>false,因为name是数组名称，指针常量不能赋值，解决方案：strcpy();
3、字符串直接进行比较的话，是其地址的比较，没有什么意义，用strcmp()函数进行比较，就是ascii码的比较了。
====================五、内存对齐================================
操作系统对于内存空间的分配，遵循如下原则：总是从2^n倍数为地址的字节处开始分配空间。
1、结构体大小
总大小是下一个类型整数倍，否则用单字节补齐，总大小指的是前面字节总数和当前的字节数之和；
2、结构体大小是最宽字节的整数倍
3、上述两个条件必须同时成立，若最终结果不成立的话，则补齐整数倍即可。
