// 05 写个从一个字符串中去除多余的空格的函数.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "stdlib.h"
#include <string.h> 
#include <stdio.h>



int _tmain(int argc, _TCHAR* argv[])
{
	void  deblank(char string[]);  /*函数声明语句*/

	char str[200];


	

	gets_s(str);
	
	deblank(str);
	//deblank("hello world");


/*
	printf("The line entered was: %s\n", str);*/


	system("pause");

	return 0;
}
void deblank(char string[]){

	int len,i;

	len = strlen(string);

	for (i = 0; i < len; i++)
	{
		if (string[i]!= ' ')
		{
			printf("%c", string[i]);
		}
		
	}


	


}