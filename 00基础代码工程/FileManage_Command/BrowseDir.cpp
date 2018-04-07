#include "stdafx.h"
#include "BrowseDir.h"
#include <direct.h>
#include <string.h>
#include <io.h>
#include "iostream"
#include <Windows.h>
#include "Md5.h"
using namespace std;




/************************************
* Access:    public 
* 函数名称:  setValueOption
* 函数功能:  工具选项设置

* 参数列表:
*   char * nPara:
*   $
* 返回值:    bool
* 
*************************************/

bool CBrowseDir::setValueOption(int nMode)
{
	// 生成模式赋-值
	m_Option = nMode;

	return false;
}

CBrowseDir::CBrowseDir()
{
	//用当前目录初始化m_szInitDir
	_getcwd(m_szInitDir, _MAX_PATH);

	//初始化数据成员m_nFileCount和m_nSubdirCount
	m_nFileCount = m_nSubdirCount = 0;

	//如果目录的最后一个字母不是'\',则在最后加上一个'\'
	int len = strlen(m_szInitDir);
	if (m_szInitDir[len - 1] != '\\')
		strcat_s(m_szInitDir, "\\");
}

/************************************
* Access:    public 
* 函数名称:  SetInitOutFile
* 函数功能:  删除存在的输出文件

* 参数列表:
*   const char * dir:
*   $
* 返回值:    bool
* 
*************************************/

bool CBrowseDir::SetInitOutFile(const char * dir)
{

	//指向const的指针不能被赋给指向非const的指针
	//另开一块内存，把字符复制过去
	m_Outfile = new char[strlen(dir) + 1];
	strcpy(m_Outfile, dir);


	//char*转wchar*
	const size_t cSize = strlen(m_Outfile) + 1;
	wchar_t* m_wOutfile = new wchar_t[cSize];
	mbstowcs(m_wOutfile, m_Outfile, cSize);


	//删除原文件
	DeleteFile(m_wOutfile);
	// 文件流句柄
	HANDLE pFile = CreateFile(m_wOutfile, GENERIC_READ | GENERIC_WRITE,
		FILE_SHARE_READ,
		NULL,
		CREATE_NEW,
		FILE_ATTRIBUTE_NORMAL,
		NULL
		);

	if (pFile ==INVALID_HANDLE_VALUE)
	{
		printf("创建失败");
	}
	
	CloseHandle(pFile);



	return true;
}

/************************************
* Access:    public 
* 函数名称:  SetInitDir
* 函数功能:  初始化遍历的目录

* 参数列表:
*   const char * dir:
*   $
* 返回值:    bool
* 
*************************************/

bool CBrowseDir::SetInitDir(const char *dir)
{
	//先把dir转换为绝对路径
	if (_fullpath(m_szInitDir, dir, _MAX_PATH) == NULL)
		return false;

	//判断目录是否存在
	if (_chdir(m_szInitDir) != 0)
		return false;

	//如果目录的最后一个字母不是'\',则在最后加上一个'\'
	int len = strlen(m_szInitDir);
	if (m_szInitDir[len - 1] != '\\')
		strcat(m_szInitDir, "\\");

	return true;
}



void CBrowseDir::FindAllFile(const TCHAR * pszPath)
{
	WIN32_FIND_DATA stcFindData = { 0 };
	TCHAR szSeach[MAX_PATH];
	wchar_t buf[MAX_PATH];
	char filename[MAX_PATH];
	wsprintf(szSeach, L"%s\\*", pszPath);
	HANDLE hFind = FindFirstFile(szSeach ,
								 &stcFindData);

	do
	{
		// 判断当前找到的文件是否是当前或上层目录
		if(wcscmp(stcFindData.cFileName , L".") == 0
		   ||
		   wcscmp(stcFindData.cFileName , L"..") == 0)
		{
			// 如果是其中之一,就结束本次循环
			continue;
		}
		
		m_nFileCount++;
		//wprintf(L"%s\\%s\n" ,pszPath,stcFindData.cFileName);
		swprintf_s(buf, 100, L"%s%s", pszPath, stcFindData.cFileName);
		WCHAR_TO_CHAR(buf, filename)
		ProcessFile(filename, stcFindData.nFileSizeLow); //处理文件函数，文件名，文件大小

		// 判断文件是否是目录
		if(stcFindData.dwFileAttributes&FILE_ATTRIBUTE_DIRECTORY)
		{
			//目录数增加
			m_nSubdirCount++;
			TCHAR path[ MAX_PATH ];
			swprintf_s(path , L"%s\\%s" , pszPath , stcFindData.cFileName);
			FindAllFile(path);
		}

	} 
	while(FindNextFile(hFind , &stcFindData));

}

bool CBrowseDir::BeginBrowse()
{
	setlocale(LC_ALL, "chs");
	TCHAR  WszInitDir[MAX_PATH];
	CHAR_TO_WCHAR(m_szInitDir, WszInitDir)
	FindAllFile(WszInitDir);
	return true;
}







/************************************
* Access:    virtual protected 
* 函数名称:  ProcessFile
* 函数功能:

* 参数列表:
*   const char * filename:文件名
*   $
* 返回值:    bool
* 
*************************************/

bool CBrowseDir::ProcessFile(const char *filename, unsigned long file_size)
{
	//char*转wchar*
	const size_t cSize = strlen(m_Outfile) + 1;
	wchar_t* m_wOutfile = new wchar_t[cSize];
	mbstowcs(m_wOutfile, m_Outfile, cSize);
	//打开现有文件
	HANDLE pFile = CreateFile(m_wOutfile, GENERIC_WRITE | GENERIC_READ,
		FILE_SHARE_READ,
		NULL,
		OPEN_EXISTING,  //文件存在
		FILE_ATTRIBUTE_NORMAL,
		NULL);

	//移动到文件尾部
	SetFilePointer(pFile, 0, 0, FILE_END);
	DWORD fileSize;

	//开辟堆空间，考虑加文件大小、文件hash的情况
	char * filename_str = new char[strlen(filename)+60];

	//判断写入是否成功
	BOOL bRet; 

    //根据输出模式判断选择哪种输出
	switch (m_Option)
	{
		// 文件大小
	    case g_FILE_SIZE: 
	    {
		   //输出文件名+文件大小
		   cout << filename<<"_"<<file_size << endl;
		   sprintf(filename_str, "%s_%d\r\n", filename, file_size);
		   bRet = WriteFile(pFile, filename_str, strlen(filename_str), &fileSize, NULL);

	    }
		break;

		// 文件hash
		case g_FILE_HASH:
		{

			//得到MD5值
			char * Md5Value = md5FileValue((char*)filename);
			//输出当前的值
			cout << filename << "_" << Md5Value << endl;
			sprintf(filename_str, "%s_%s\r\n", filename, Md5Value);
			bRet = WriteFile(pFile, filename_str, strlen(filename_str), &fileSize, NULL);


		}
		break;

		// 文件大小+HASH
		case 4:
		{
			//得到MD5值
			char * Md5Value = md5FileValue((char*)filename);
			//输出当前的值
			cout << filename << "_" << file_size << "_" <<  Md5Value << endl;
			sprintf(filename_str, "%s_%d_%s\r\n", filename, file_size,Md5Value);
			bRet = WriteFile(pFile, filename_str, strlen(filename_str), &fileSize, NULL);


		}
		break;

		// 默认情况下只输出文件名
		default:
		{
			//输出文件名
			cout << filename << endl;
			sprintf(filename_str, "%s\r\n", filename);
			bRet = WriteFile(pFile, filename_str, strlen(filename_str), &fileSize, NULL);
		}
		break;
	}


	// 输出调试信息
	if (bRet)
	{
        //输出写入的文件
		WCHAR test[260];
		CHAR_TO_WCHAR(filename_str,test);
		//输出调试信息
		OutputDebugString(test);
		OutputDebugString(TEXT("WriteFile 写文件成功\r\n"));
	}

	//好的编码习惯是开了水龙头就要关掉水龙头
	delete[] filename_str;
	CloseHandle(pFile);

	return true;
}





int CBrowseDir::GetFileCount()
{
	return m_nFileCount;
}





/************************************
* Access:    public
* 函数名称:  FunctionMain
* 函数功能:

* 参数列表:
*   char * Para1:参数1
*   char * Para2:搜集到的路径
*   char * Para3:参数2
*   char * Para4:匹配的文本路径
*   char * Para5:输出的配置 0 name 1 size 2 hash
*   $
* 返回值:    int
*
*************************************/

int CBrowseDir::BrowseDir_function(char * Para1, char * Para2, char * Para3, char * Para4, int nMode)
{

	//设置输出模式 0是文件名 1是文件大小，2是hash
	setValueOption(nMode);



	//设置要遍历的目录
	if (!SetInitDir(Para2))
	{
		puts("目录不存在。");
		return 0;
	}


	//判断特征码文件是否已经生成过，存在则删除
	SetInitOutFile(Para4);

	//开始遍历
	BeginBrowse();
	printf("\n文件总数: %d\n子目录总数:%d\n", GetFileCount(), GetSubdirCount());
	system("pause");

	return 0;

}

//返回子目录个数
int CBrowseDir::GetSubdirCount()
{
	//因为进入初始目录时，也会调用函数ProcessDir，
	//所以减1后才是真正的子目录个数。
	return m_nSubdirCount;
}


