// 04_06_定义一个保存坦克信息的结构体.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <process.h>

typedef struct _TankInfo
{

	int nNum;
	char szName[20];
	int weapon;
	int nScore;
}TankInfo, *TankINFO;

int _tmain(int argc, _TCHAR* argv[])
{

	TankInfo  zzz = { 1, "zzz", 5, 100 };
	printf(" 号码： %d \n 坦克名：  %s \n  武器是： %d \n  成绩是： %d \n",zzz.nNum,zzz.szName,zzz.weapon,zzz.nScore);
	system("pause");
	return 0;
}

