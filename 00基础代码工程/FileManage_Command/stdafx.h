// stdafx.h : 标准系统包含文件的包含文件，
// 或是经常使用但不常更改的
// 特定于项目的包含文件
//

#pragma once

#include "targetver.h"

#include <stdio.h>
#include <tchar.h>



// TODO:  在此处引用程序需要的其他头文件
//多字符转换为宽字符(unicode -- > ascll)
#define CHAR_TO_WCHAR(lpChar,lpW_Char) MultiByteToWideChar(CP_ACP,NULL,lpChar,-1,lpW_Char,_countof(lpW_Char));

enum Option {
	g_FILE_NAME = 0, 	 //文件名
	g_FILE_SIZE, 		 //文件大小
	g_FILE_HASH		 //文件HASH
};
