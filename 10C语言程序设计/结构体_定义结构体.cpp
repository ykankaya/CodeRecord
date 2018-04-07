// 5_定义结构体.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "stdlib.h"
#include  <string.h>


//1.定义结构体类型
//语法1： 不推荐使用语法
//struct _PERSON
//{
//	char name[20];
//	char sex;
//	int age;
//	float height;
//}stc_xiaoming = {};


typedef struct _PERSON
{
	char name[20];
	char sex;
	int age;
	double height;
}newName;

newName stc1;
_PERSON stc2; //全局变量


int _tmain(int argc, _TCHAR* argv[])
{

	//2.定义结构体变量，并初始化内存为0
	_PERSON xiaolv;   //局部变量

	//释放内存空间，置于0
	memset(&xiaolv, 0, sizeof(_PERSON));


	// 初始化结构体变量
	_PERSON xiaohong = { "小红", 'M', 18, 3.14 };
	xiaolv = xiaohong;
	printf("%d", sizeof(_PERSON));


	//3.使用结构体
	xiaolv.age = 18;
	xiaolv.height = xiaohong.height;
	xiaolv.sex = 'F';

	strcpy_s(xiaolv.name,20, xiaohong.name);

    printf(" 名字：%s\n ",xiaolv.name);
	printf(" 性别：%c\n ", xiaolv.sex);
	printf(" 年龄：%d\n ", xiaolv.age);
	printf(" 身高 ：%f\n ", xiaolv.height);



	//4.定义结构体数组

	_PERSON per2[] = { {"lilei",'M',25,1.8},
	                     { "hanmeimei", 'F', 23, 165.8 },
	
                   };

	int struct_len = sizeof(per2) / sizeof(per2[0]);

	//5.使用结构体数组
	for (int i = 0; i < _countof(per2);i++)
	{

		printf(" 名字：%s \n ", per2[i].name);
		printf(" 性别：%c \n ", per2[i].sex);
		printf(" 年龄：%d \n ", per2[i].age);
		printf(" 身高：%f \n ", per2[i].height);

	}

	system("pause");

	return 0;
}
