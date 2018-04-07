// 04_01_输入三个数将三个数的最大值输出到屏幕上.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <process.h>


int _tmain(int argc, _TCHAR* argv[])
{
	int a = 3, b = 2, c = 4,d,max;

	d = a > b ? a : b;
	max = d > c ? d : c;
	printf(" %d \n ",max);

	system("pause");

	return 0;
}

