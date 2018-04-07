// 05_02_编写函数判断素数，是返回1否则0.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "stdlib.h"
#include  <string.h>


int _tmain(int argc, _TCHAR* argv[])
{
	int  prime(int n);
	int s;
	//素数输入位置
	s = prime(17);

	printf(" %d \n ",s);

	system("pause");

	return 0;
}
int prime(int n){

	int flag=1;
	for (int i = 2; i < n&&flag==1;i++)
	{
		if (n%i==0)
		{
			flag = 0;
		}
	}
	return flag;
}

