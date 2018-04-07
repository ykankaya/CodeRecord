#pragma once
#include <vector>
#include <string>
using std::vector;
using std::string;

class CopyFileToDir
{
public:
	CopyFileToDir();

	bool ReadTXTFile_GetPath(char * PathText, char *Path);
	//对比目标目录
	vector <string> vecTatgetPath;

	~CopyFileToDir();
};

