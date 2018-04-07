#include<stdio.h>

#include<stdlib.h>

#include<string.h>

int main(void)

{
	int Numa, Numb;

	// 错误案例
	// 错误写法，使用putchar只能输出一个字符，且无法参与运算
    //     
	//numa = getchar();
	//fflush(stdin);
	//numb = getchar();
	//putchar(numa + numb);
	//putchar(numa - numb);
	//putchar(numa * numb);
	//putchar(numa / numb);

	// 
	//正确写法
	// 

	printf("请从键盘输入两个数字\n");
	scanf_s("%d", &Numa);
	getchar();
	scanf_s("%d", &Numb);
	printf("+（和）的结果为%d \n", Numa + Numb);
	printf("-（差）的结果为%d \n", Numa - Numb);
	printf("*（积）的结果为%d \n", Numa * Numb);
	printf("/（商）的结果为%d \n", Numa / Numb);
    system("pause");
    return 0;

}