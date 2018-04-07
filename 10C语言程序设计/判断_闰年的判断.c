#include<stdio.h>

#include<stdlib.h>

#include<string.h>


int main(void)

{
	int nYear;

	printf(" 输入一个数字 \n ");
	scanf_s("%d", &nYear);

	if ((nYear % 4 == 0 && nYear % 100 != 0) || (nYear % 400 == 0))
	{

		printf(" %d 为闰年 \n ", nYear);
	} 
	else
	{
		printf(" %d 不为闰年 \n ", nYear);
	}
    system("pause");
    return 0;

}