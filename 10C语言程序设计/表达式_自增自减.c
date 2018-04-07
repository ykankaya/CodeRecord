#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

#include<stdlib.h>

#include<string.h>





int main()

{
	//int i = 10;

	////自增的同时，还参与了别的运算，那么就先参与运算，再自增；
	//printf("%d", i++); //输出10
	////自增的同时，还参与了别的运算，那么就先自增，再参与运算；
	//printf("%d", ++i); //输出12

	int num = 2, i = 6;
	do
	{
		i--;       
		num++;         //   num = 3 4 5
		 
	} while (--i);     //i = 4 2 0
	printf("%d",num);  //结果为5
	system("pause");
   return 0;
}