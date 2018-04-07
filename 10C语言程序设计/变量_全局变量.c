// 变量类型.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "stdlib.h"

void fun1(){
   // printf(" fun1 %x\n ",g_nNum);

}

int g_nNum = 0x09999999;

void fun2(){

	printf(" fun2 %x \n ", g_nNum);

}

int _tmain(int argc, _TCHAR* argv[])
{
	printf(" main %x \n ",g_nNum);
	g_nNum = 0x110;
	fun2();
	printf(" main %x \n ", g_nNum);

	system("pause");
	return 0;
}

