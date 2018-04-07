// 04_03_获取int整数，计算二进制位多少个位是1.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <process.h>

//二进制有多少个1
void toralone(int x)
{
	int count = 0;
	int x1;
	//int x2;
	while (x)
	{
		x1 = x % 2 ;            //求余数，求二进制
		//x2 = x / 10; 
		if (x1==1)
		{
			count++;
		}
		x /= 2;                 //向右边移动一位
	}
	printf("count= %d \n ",count);
}



int _tmain(int argc, _TCHAR* argv[])
{
	toralone(4);
	system("pause");
	return 0;
}

