// 04_05_定义结构体包括学院，学生姓名，分数.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <process.h>

typedef struct _StuInfo
{

	int nNum;
	char szName[20];
	char nScore;
}STUINFO,*PSTUINFO;
int _tmain(int argc, _TCHAR* argv[])
{
	_StuInfo student1 = { 25, "liming", 88 };
	printf(" 学生年龄为：%d\n 学生姓名为：%s \n 成绩为：%d \n",student1.nNum,student1.szName,student1.nScore);
	system("pause");
	return 0;
}

