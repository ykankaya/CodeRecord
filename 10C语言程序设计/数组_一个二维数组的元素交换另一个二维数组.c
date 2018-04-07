// 一个二维数组的元素交换另一个二维数组.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "stdlib.h"

// a = { 1,2,3 }
//	   { 4,5,6 }

// b = { 1,4 }
//     { 2,5 }
//     { 3,6 } 


int main()
{
	int a[2][3] = { { 1, 2, 3 }, {4,5,6} };
	int b[3][2] = { 0 };

	printf(" a数组值 ：\n ");
	for (int row = 0; row < 2; row ++)
		{
			for (int col = 0; col < 3; col ++)
			{
				printf("  a[%d][%d] = %d \n ",row,col,a[row][col]);
				b[col][row] = a[row][col];
			}
			printf(" \n ");
		}
	printf(" b数组值：\n ");
	for (int  i = 0; i < 3; i++)
	{

		for (int j = 0; j < 2; j++){
		
			printf(" b[%d][%d]=[%d]\n ",i,j,b[i][j]);
		}
		printf(" \n ");
	}


	system("pause");

	return 0;
}