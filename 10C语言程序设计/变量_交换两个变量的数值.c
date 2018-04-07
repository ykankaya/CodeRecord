#include<stdio.h>

#include<stdlib.h>

#include<string.h>

int main(void)

{
	int a = 10;
	int b = 20;
	int t;

	printf("a的原始值是%d \n",a);
	printf("b的原始值是%d \n", b);
	printf("交换值开始 \n");
	t = a;
	a = b;
	b = t;
	printf("a的交换值是%d \n", a);
	printf("b的交换值是%d \n", b);
	printf("交换值结束\n");


    system("pause");
    return 0;

}