#include<stdio.h>

#include<stdlib.h>

#include<string.h>

int main(void)

{

	int nNum = 0;
	printf(" 输入一个数字 \n ");
	scanf_s("%d", &nNum);

	if (nNum % 2 == 0)
	{
		printf(" Yes \n ");
	}
	else
	{
		printf(" No \n ");
	}
    system("pause");
    return 0;

}