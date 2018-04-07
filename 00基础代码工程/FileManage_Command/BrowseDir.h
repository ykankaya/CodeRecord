#pragma once
#include <stdlib.h>
#include <corecrt_io.h>


//宽字符转换为多字符(unicode -- > ascll)
#define WCHAR_TO_CHAR(lpW_Char,lpChar) WideCharToMultiByte(CP_ACP,NULL,lpW_Char,-1,lpChar,_countof(lpChar),NULL,FALSE);

//多字符转换为宽字符(unicode -- > ascll)
#define CHAR_TO_WCHAR(lpChar,lpW_Char) MultiByteToWideChar(CP_ACP,NULL,lpChar,-1,lpW_Char,_countof(lpW_Char));


class CBrowseDir
{
protected:
	//存放初始目录的绝对路径，以'\'结尾
	char m_szInitDir[_MAX_PATH];
	//输出的文件名
	char *m_Outfile;


	//文件结构信息
	_finddata_t fileinfo;


	//-size=1 -hash=2 -name=0
	int m_Option;


	int m_nFileCount;   	//保存文件个数

	int m_nSubdirCount; 	//保存子目录个数


public:

	// 赋值给m_option，0是文件名 1是文件大小，2是hash
	bool setValueOption(int nMode);

	//缺省构造器
	CBrowseDir();

	//设置初始目录为dir，如果返回false，表示目录不可用
	bool SetInitDir(const char *dir);

	//设置初始输出的文件
	bool SetInitOutFile(const char *dir);


	//开始遍历初始目录及其子目录下由filespec指定类型的文件
	//filespec可以使用通配符 * ?，不能包含路径。
	//如果返回false，表示遍历过程被用户中止
	bool BeginBrowse();

	//返回文件个数
	int GetFileCount();
	// 查找,匹配生成模式
	int BrowseDir_function(char *Para1, char *Para2, char *Para3, char *Para4, int nMode);
	//返回子目录个数
	int GetSubdirCount();


	//遍历目录
	void FindAllFile(const TCHAR* pszPath);

protected:

	//函数BrowseDir每找到一个文件,就调用ProcessFile
	//并把文件名作为参数传递过去
	//如果返回false,表示中止遍历文件
	//用户可以覆写该函数,加入自己的处理代码
	//覆写虚函数ProcessFile，每调用一次，文件个数加1
	 bool ProcessFile(const char *filename, unsigned long filesize );


};
