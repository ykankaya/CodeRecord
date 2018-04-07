// 04_02_读入整数判断7的倍数或尾数含有7的数.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <process.h>


int _tmain(int argc, _TCHAR* argv[])
{
	int nNum = 50;

	if ((nNum%7==0)||(nNum%10==7))
	{
		printf(" yes");
	}
	else{
		printf(" no ");
	}
	system("pause");
	return 0;
}

