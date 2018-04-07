// 05_00_指针与数组.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "stdlib.h"
#include  <string.h>
#include  <cstring>
#include <crtdbg.h>

int _tmain(int argc, _TCHAR* argv[])
{
	char  str[][10] = { "hello", "Google"};
	char * p = str[0];
		printf(" %d\n ",strlen(++p));

	system("pause");

	return 0;
}