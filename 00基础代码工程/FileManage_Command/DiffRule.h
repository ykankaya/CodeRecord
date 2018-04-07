#pragma once
#include <vector>
#include <string>
using std::vector;
using std::string;

class CDiffRule
{
public:
	CDiffRule();


	// 主要对比规则功能函数
	int DiffRuleProcess(char * nPara1,char * nPara2);
	// 判断输入文件是否存在
	bool ifstreamProcess(char* nFile_Name);
	// 读取中毒机器生成的文件特征库
	bool TargetRule(char* nFile_Name);
	// 读取本地机器生成的文件特征库
	bool DiffRule(char* nFile_Name);
	// vector处理函数
	bool vecFileProcess();
	vector<int>vecIndex;
	//对比目标目录
	vector <string> vecTatgetRule;
	//特征规则
	vector <string> vecDiffRule;
	~CDiffRule();
};

