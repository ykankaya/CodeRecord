// FileManage_Command.cpp : 定义控制台应用程序的入口点。
//
#include "stdafx.h"
#include "stdlib.h"
#include "stdio.h" 
#include "iostream"
#include "BrowseDir.h"
#include <windows.h>
#include  <fstream>
#include  < string >
#include "DiffRule.h"
#include "CopyFileToDir.h"
using namespace std;



/************************************
* Access:    public 
* 函数名称:  usage
* 函数功能:  软件用法说明函数

* 参数列表:
*   $
* 返回值:    void
* 
*************************************/

void usage() 
{
	printf("\nauthor:zzzhhh\n");
	printf("\nExample: \n\n");
	printf("\t1.生成特征码:\n\tFileManage.exe -Find 要查找的目录 -Output 要生成的文件\n\t -name 只生成文件名|| -size 生成文件名+大小|| -hash 文件MD5值 \n\n");
	printf("\tFileManage.exe -Find C:\\Windows -Output C:\\target.txt  -name || -size ||-hash \n\n");
	printf("\t2.对比目录:\n\tFileManage.exe -diff 对比的目录 -Rule 事先生成的规则\n\t -L 默认对比每行 -B 对比每字节\n\n");
	printf("\tFileManage.exe -Diff target.txt -Rule diff_Name.txt\n\t -L||-B \n\n");
	printf("\t3.批量复制文件到某个目录内:\n\t -C 存有文件名的.txt -Output 复制过去的目录\n\n");
	printf("\tFileManage.exe -C target.txt -Output D:\\save-dir \n\n");
}


int main(int argc, char* argv[])
{

	//Debug调试信息
	//argc = 5;
	//argv[1] = "-diff";                                  //参数1  -find 查找文件   -diff 对比目录 -C 复制文件名
	//argv[2] = "D:\\windows-dir.txt";                    //参数2  需要生成文件名的目录
	//argv[3] = "-rule";                                //参数3  -output 输出文件 -rule 选择规则
	//argv[4] = "D:\\target.txt";                         //参数4  输出的文件名存放的路径
	//argv[5] = "-hash";                              //参数5  -name 文件名  -size 文件名+大小 -hash 文件名+md5



	//目录浏览类
	CBrowseDir BrowseDir;
	//规则对比类
	CDiffRule DiffRule;
	//目录文件拷贝
	CopyFileToDir CopyfFile;

	//工具说明
	usage();


	//Debug 判断参数是否达标在决定是否向下走
	if (argc < 5)
	{
		printf("参数输入不正确，请重新输入!\n");
		return 0;
	}


	// 判断第一个参数名是否为查找或对比
	if ((strcmp(argv[1], "-Find") == 0) || 
		(strcmp(argv[1], "-find") == 0))
	{

		// 判断第二个参数名是否为输出或规则
		if ((strcmp(argv[3], "-Output") == 0) ||
			(strcmp(argv[3], "-output") == 0))

		{
			//清屏命令
			system("cls");


			if (argc !=6)
			{
				BrowseDir.BrowseDir_function(argv[1], argv[2], argv[3], argv[4], g_FILE_NAME);
			}


			//主要功能函数实现 - 生成文件名
			if ((strcmp(argv[5], "-NAME") == 0) ||
				(strcmp(argv[5], "-name") == 0)) 
			{
				BrowseDir.BrowseDir_function(argv[1], argv[2], argv[3], argv[4], g_FILE_NAME);
			}
			// 主要功能函数实现 - 生成文件大小
			if ((strcmp(argv[5], "-SIZE") == 0) ||
				(strcmp(argv[5], "-size") == 0))
			{
				BrowseDir.BrowseDir_function(argv[1], argv[2], argv[3], argv[4], g_FILE_SIZE);
			}
			// 主要功能函数实现 - 生成文件HASH
			if ((strcmp(argv[5], "-HASH") == 0) ||
				(strcmp(argv[5], "-hash") == 0))
			{
				BrowseDir.BrowseDir_function(argv[1], argv[2], argv[3], argv[4], 4);
			}
		}

		return 0;
	} 
	
	
	
	// 对比功能
	if ((strcmp(argv[1], "-Diff") == 0) ||
		(strcmp(argv[1], "-diff") == 0))
	{


		//判断第二个参数名是否为输出或规则
		if ((strcmp(argv[3], "-Rule") == 0) ||
			(strcmp(argv[3], "-rule") == 0)) 
		{
			//清屏命令
			system("cls");
			//编程思路：
			//  0.文件是否存在
			DiffRule.DiffRuleProcess(argv[2], argv[4]);
		}


	} 


	// 复制指定MD5的文件到指定的文件夹
	
	if (0 == strcmp("-C", argv[1]))
	{			

        if (argc !=6)
		{
			// 读取文本文件到vector，（含有路径）
		    CopyfFile.ReadTXTFile_GetPath(argv[2], argv[4]);
		}




		// 指定的目录
	}
	else
	{
		system("cls");
		usage();
		printf("请输入正确参数名\n");
		return 0;
	}

	return 0;

}