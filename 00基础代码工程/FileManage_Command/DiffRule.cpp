#include "stdafx.h"
#include "DiffRule.h"
#include <windows.h>
#include <fstream>  
#include <string>  
#include <iostream>  
using namespace std;

CDiffRule::CDiffRule()
{
}






/************************************
* Access:    public 
* 函数名称:  DiffRuleProcess
* 函数功能:  主要对比规则功能函数

* 参数列表:
*   char * nPara1: 第一个参数的文件夹路径：中毒机器的特征码
*   char * nPara2: 第二个参数的文件夹路径：取样机器的特征码
*   $
* 返回值:    int
* 
*************************************/

int CDiffRule::DiffRuleProcess(char * nPara1, char * nPara2)
{
	// 先判断路径是不是为正确的
	if ( !ifstreamProcess(nPara1))
	{
		system("cls");
		printf("\n %s \n文件路径不存在。", nPara1);
		return 0;
	}
	// 先判断特征库路径是不是为正确的
	if (!ifstreamProcess(nPara2))
	{
		system("cls");
		printf("\n %s \n文件路径不存在。", nPara2);
		return 0;
	}

	// 初始化对比的向量
	TargetRule(nPara1);
	DiffRule(nPara2);

	// 开始遍历对比
	vecFileProcess();

    // begindiff();

	
	return 0;
}

/************************************
* Access:    public
* 函数名称:  ifstreamProcess
* 函数功能:  输入的文件名处理

* 参数列表:
*   $
* 返回值:    bool
*
*************************************/

bool CDiffRule::ifstreamProcess(char* nFile_Name)
{

	//char*转wchar*
	const size_t cSize = strlen(nFile_Name) + 1;
	wchar_t* wFile_Name = new wchar_t[cSize];
	mbstowcs(wFile_Name, nFile_Name, cSize);

	HANDLE pFile = CreateFile(wFile_Name, GENERIC_WRITE | GENERIC_READ,
		FILE_SHARE_READ,
		NULL,
		OPEN_EXISTING,
		FILE_ATTRIBUTE_NORMAL,
		NULL);
	//判断文件是否存在
	if (pFile == INVALID_HANDLE_VALUE)
	{
		printf("未找到文件,请检查文件是否存在\n %s", nFile_Name);
		return false;
	}

	return true;
}

/************************************
* Access:    public 
* 函数名称:  TargetRule
* 函数功能:  读取中毒机器生成的文件特征库

* 参数列表:
*   char * nFile_name:文件名，逐行读取
*   $
* 返回值:    bool
* 
*************************************/

bool CDiffRule::TargetRule(char * nFile_name)
{
	ifstream in(nFile_name);
	string filename;
	string line;

	//接受文件计数
	int num = 0;

	if (in) // 有该文件  
	{
		while (getline(in, line)) // line中不包括每行的换行符  
		{
			vecTatgetRule.push_back(line);
			num++;

		}
	}
	else // 没有该文件  
	{
		cout << "no such file" << endl;
	}
	cout <<"对比文件个数为"<< num << endl;

	return false;
}

/************************************
* Access:    public 
* 函数名称:  DiffRule
* 函数功能:  读取本地机器生成的文件特征库

* 参数列表:
*   char * nFile_Name:文件名，逐行读取
*   $
* 返回值:    bool
* 
*************************************/

bool CDiffRule::DiffRule(char* nFile_Name)
{
	ifstream in(nFile_Name);
	string filename;
	string diff_line;

	//接受文件计数
	int num = 0;

	if (in) // 有该文件  
	{
		while (getline(in, diff_line)) // line中不包括每行的换行符  
		{

			vecDiffRule.push_back(diff_line);

			num++;

		}
	}
	else // 没有该文件  
	{
		cout << "no such file" << endl;
	}


	cout << "病毒库对比文件个数为" << num << endl;

	return false;

}

/************************************
* Access:    public 
* 函数名称:  vecFileProcess
* 函数功能:  对比两个文件中重复的值，然后去除。留下【中毒机器文件名】中不重复的文件名

* 参数列表:
*   $
* 返回值:    bool
* 
*************************************/

bool CDiffRule::vecFileProcess()
{
	int nCount = 0;


	//删除相似的
	for (size_t i = 0; i< vecDiffRule.size(); i++)
	{
		for (size_t j=0;j<vecTatgetRule.size();)
		{

			int nRet = strcmp(vecDiffRule[i].c_str(), vecTatgetRule[j].c_str());

			if (nRet==0)
			{
				//vecTatgetRule.erase(vecTatgetRule.begin()+j);
				//cout << vecTatgetRule[j].c_str() << "为相同文件" << endl;
				vecTatgetRule.erase(vecTatgetRule.begin() + j);

			}
			else
			{
				j++;
			}
		}

	}

	//输出不同的
	for (size_t i=0;i<vecTatgetRule.size();i++)
	{
		cout << "不同处为：" << vecTatgetRule[i].c_str()  <<endl;
	}

	system("pause");
	return false;
}


CDiffRule::~CDiffRule()
{
}
