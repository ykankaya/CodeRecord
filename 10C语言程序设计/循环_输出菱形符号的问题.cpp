// 输出菱形符号的问题.cpp : 定义控制台应用程序的入口点。
//


#include "stdafx.h"
#include <windows.h>
#include <iostream>
using std::cout;
using std::cin;
using std::endl;


int _tmain(int argc, _TCHAR* argv[])
{


	int row, col, col2;


			//         *
			//        ***
			//       *****
			//        ***
			//         *





	        /*                上半部分*/
			//         行数   空格   符号
			//         1      2      1                2*i-1                 
			//         2      1      3                2*i-1                 
			//         3      0      5                2*i-1                  




	       /*上半部分*/
			for (row = 1; row <= 3; row++)
			{

				for (col = 1; col <=3-row; col++)
				{
					cout << " ";
				}


				for (col2 = 1; col2 <= 2 * row - 1; col2++)
				{
					cout << "*";
				}
				cout << "" << endl;
			}



			//         *
			//        ***
			//       *****
			//        ***
			//         *

			/*                下半部分*/
			//         行数   空格   符号
			//         1      1       3                   5-2*1  = 3
 			//         2      2       1                   5-2*2  = 1

			//下半部分

			for (row = 1; row <= 2;row++)
			{
				for (col = 0; col < row;col++)
				{
					cout << " ";
				}
				for (col2 = 0; col2 < 5 - 2 * row;col2++)
				{
					cout << "*";

				}
				cout << "" << endl;
			}





	system("pause");
	
	return 0;
}
