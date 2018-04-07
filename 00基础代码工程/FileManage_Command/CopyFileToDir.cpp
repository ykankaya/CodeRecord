#include "stdafx.h"
#include "CopyFileToDir.h"
#include <fstream>  
#include <string>  
#include <iostream>  
#include <windows.h>


//宽字符转换为多字符(unicode -- > ascll)
#define WCHAR_TO_CHAR(lpW_Char,lpChar) WideCharToMultiByte(CP_ACP,NULL,lpW_Char,-1,lpChar,_countof(lpChar),NULL,FALSE);

//多字符转换为宽字符(unicode -- > ascll)
#define CHAR_TO_WCHAR(lpChar,lpW_Char) MultiByteToWideChar(CP_ACP,NULL,lpChar,-1,lpW_Char,_countof(lpW_Char));

using namespace std;

CopyFileToDir::CopyFileToDir()
{
}

bool CopyFileToDir::ReadTXTFile_GetPath(char * PathText,char *Path)
{

	//打开文件
	ifstream in(PathText);
	string filename;
	string line;

	//接受文件计数
	int num = 0;

	if (in) // 有该文件  
	{
		while (getline(in, line)) // line中不包括每行的换行符  
		{
			//读取文本内容到vector中
			vecTatgetPath.push_back(line);
			num++;

		}
	}
	else // 没有该文件  
	{
		cout << "no such file" << endl;
	}
	cout << "对比文件个数为" << num << endl;


	WCHAR  W_Dir[MAX_PATH];
	WCHAR W_FilePath[MAX_PATH];
	WCHAR W_FileName[MAX_PATH];



	for (size_t i = 0; i < vecTatgetPath.size(); i++)
	{

		CHAR_TO_WCHAR(Path, W_Dir);
		CHAR_TO_WCHAR(vecTatgetPath[i].c_str(), W_FilePath);
		//取文件名
		size_t found = vecTatgetPath[i].find_last_of("/\\");
		CHAR_TO_WCHAR(vecTatgetPath[i].substr(found).c_str(), W_FileName);
		lstrcat(W_Dir,W_FileName);

		if (!CopyFile(W_FilePath, W_Dir, TRUE))
		{
			//LastError == 0x50，文件存在。
			if (GetLastError() == 0x50)
			{
				printf("文件%ls已经存在，是否覆盖？y/n：", W_Dir);
				if ('y' == getchar())
				{
					//复制，覆盖已经存在的文件。
					if (!CopyFile(W_FilePath, W_Dir, FALSE))
					{
						printf("复制文件错误，%d\n", GetLastError());
					}
					else
					{
						printf("复制成功！\n");
					}
				}
				else
				{
					return 0;
				}
			}
		}
		else
		{
			printf("%ls 复制成功！\n", W_FileName);
		}

	}


	


	return false;


}


CopyFileToDir::~CopyFileToDir()
{
}
