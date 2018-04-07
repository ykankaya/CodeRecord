// 04 编写简易的printf函数.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "stdlib.h"
#include <string.h>
#include <stdarg.h>

int main()
{

	int MyPrintf(char szFormat[], int nNumb);

	int dec = 1234;
	MyPrintf("%d", dec);
	system("pause");

	return 0;
}
int MyPrintf(char szFormat[], int nNumb){

	int s;
	s = printf(szFormat, nNumb);
	return s;

}