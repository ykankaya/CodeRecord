// 06 统计不同字符出现频度.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "stdlib.h"
#include <stdio.h>
#include <string.h>

int main()
{
	char a = 0;
	int num_count = 0;
	int space_count = 0;
	int other_count = 0;
	//注意此处，不能写成a=getchar(),然后while(a!='\n'),这样做只能输入一行，然后进行死循环
	while ((a = getchar()) != '\n')
	{
		if (a >= '0'&&a <= '9')
		{
			num_count++;
		}
		else if (a == ' ')
		{
			space_count++;
		}
		else
		{
			other_count++;
		}
	}
	printf("num_count=%d\n", num_count);
	printf("space_count=%d\n", space_count);
	printf("other_count=%d\n", other_count);
	system("pause");
	return 0;
}
