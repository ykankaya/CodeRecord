// 04_05_数组a中n个数组按相反顺序存放.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <process.h>
#include <string.h>



void change(int array[], int n){

	int temp, i, j;
	int m = (n - 1) / 2;      //要对换的次数
	for (i = 0; i <= m;i++)   
	{
		j = n - 1 - i;        //头尾互换
		temp = array[i];
		array[i] = array[j];
		array[j] = temp;
	}
	return;

}


int _tmain(int argc, _TCHAR* argv[])
{
	int i, a[10] = { 3, 7, 9, 11, 0, 6, 7, 5, 4, 2 };
	printf(" The original array \n ");
	for (i = 0; i < 10;i++)
	{
		printf("%d",a[i]);
	}
	printf(" \n ");
	int len = sizeof(a)/sizeof(a[0]);   //计算数组长度
	change(a, len);
	printf(" The array has been inverted \n ");
	for (i = 0; i < 10;i++)
	{
		printf("%d",a[i]);          //输出目前数组的值
	}
	system("pause");
	return 0;
}

