// 05_04_不要strlen函数求一个字符串的长度.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "stdlib.h"
#include  <string.h>

struct TestA
{
	float math;
	float English;
	float Chinese;
}xiaohong = {2,2,2};
struct TestB
{
	char Name[20];
	int StuNumb;
	TestA objA;
};
TestA stc1;
TestB stc2;  //全局变量


int _tmain(int argc, _TCHAR* argv[])
{
	//TestA xiaohong = { 2, 2, 175 };
	printf("TestA 为：%d \n", sizeof(TestA));
	printf("TestB 为：%d \n", sizeof(TestB));
	printf("名字:%f \n", xiaohong.math);
	printf("性别:%f \n", xiaohong.English);
	printf("年龄:%f \n", xiaohong.Chinese);

	system("pause");

	return 0;
}

