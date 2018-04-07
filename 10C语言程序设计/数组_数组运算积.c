// 03 数组运算积.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "stdlib.h"

int _tmain(int argc, _TCHAR* argv[])
{

	int arrayA[10];
	int arrayB[10];
	int arrayC[10];
	int i;


	/*1.获取数组A的十个元素,并输出内容*/

	printf("请依次输入数组A中的10个整数：\n");
	for (i = 0; i < 10; i++){
		printf(" arrayA[%d] == \n ", i);
		scanf_s("%d", &arrayA[i]);
	}
	system("cls");
	printf("数组A输入的10个整数为：\n");
	for (i = 0; i < 10; i++){
		printf("%d ", arrayA[i]);

	}


	/*2.获取数组B的十个元素，并输出内容*/

	printf("请依次输入数组B中的10个整数：\n");
	for (i = 0; i < 10; i++){
		printf(" arrayB[%d] \n ", i);
		scanf_s("%d", &arrayB[i]);
	}

	printf(" \n");
	printf("数组B输入的10个整数为：\n");
	for (i = 0; i < 10; i++){
		printf("%d ", arrayB[i]);
	}
	printf(" \n");



	/*3.将数组A与数组B的值输入数组C，并输出内容*/

	printf("数组C为arrayA[]与arrayB[]的积：\n");
	for (i = 0; i < 10; i++){
		arrayC[i] = arrayA[i] * arrayB[i]; //得到相乘结果存入C数组.
		printf("arraryC[%d] == %d \n", i, arrayC[i]);
	}



	printf("\n");

	system("pause");

	return 0;
}