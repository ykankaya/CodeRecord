#include<stdio.h>

#include<stdlib.h>

#include<string.h>

int main(void)

{
	int Num = 100;
	printf("num的值是%d \n",Num);
    printf("请输入一个数字\n ");
	scanf_s("%d", &Num);
    printf("你输入的值是%d \n",Num);
	
    system("pause");
    return 0;

}