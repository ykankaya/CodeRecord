// 定义指针.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "stdlib.h"
#include  <string.h>


int _tmain(int argc, _TCHAR* argv[])
{

	//1.定义一个指针，并使用
	int * p = nullptr;  //nullptr等于0
	int nNum = 100;

	//注意：地址也区分类型
	char ch = 'H'; 

	p = &nNum;

	//输出
	printf(" %x \n ",p);
	printf(" %x \n ",*p);
	
	//赋值
	*p = 200;

	//指针相关的数据
	printf("指针的值（地址）: %x \n ", p);
	printf("指针的值指向的内容(int): %x \n ", *p);
	printf("指针变量的地址（地址）: %x \n ", &p);
	printf("int变量的地址（地址）: %x \n ", &nNum);

	//2.指针的运算
	printf("指针的值（地址+1）: %x \n ", p+1);
	printf("指针的解引用（+1）: %x \n ", *p + 1);

	//3.一级指针与一维数组的关系
	//数组名就是首地址元素的地址
	int arr[10];
	int * pArr = arr;

	//二维数组与指针
	//int arr1[10][10];
	//int(*p)[10] = arr1;


	////	三维数组
	//int arr2[10][10][30];
	//int(*p)[10][30] = arr2;


	//四种方式操作指针数组，arr[i] <-> *(arr+1)

	for (int i = 0; i < 10;i++)
	{
		printf(" %d \n ",arr[i]);  //1.下标运算符 []方式操作数组
		printf(" %d \n ", pArr[i]);   //使用数组名/地址
		printf(" %d \n ", *(arr + 1)); //2.指针的方式操作数组
		printf(" %d \n ", *(pArr + i)); //使用数组名 /地址
	}

	//使用变量地址与指针对比
	int a;
	scanf_s("%d", &a);

	char str[100];
	//指针就是地址，所以不需要&符号；
	scanf_s("%s",str,100);







	system("pause");

	return 0;
}

