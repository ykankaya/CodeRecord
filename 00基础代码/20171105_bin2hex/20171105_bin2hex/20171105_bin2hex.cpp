// 20171105_bin2hex.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <stdlib.h>
#include <string.h>

//Win32 + *nix
#ifdef WIN32
#define CRLF    "\r\n"
#else
#define CRLF    "\n"
#endif

//number of bytes per line
#define LINELEN     16

void printFileAsHex(FILE* file);
char toVisibleCharacter(int byteVal);
void writeLine(char* lineBuffer, int buflen);
char upperToHex(int byteVal);
char lowerToHex(int byteVal);
char nibbleToHex(int nibble);


int main(int argc, const char* argv[])
{
	FILE* file;

	//if (argc != 2)
	//{
	//	printf("Usage: phex <file>");
	//	printf(CRLF);
	//	return 1;
	//}

	// 读写文件
	file = fopen("D:\\20171111-test.exe", "rb");  //打开文件
	if (NULL == file)
	{
		printf("Cannot open %s", argv[1]);
		printf(CRLF);
		return 2;
	}

	printFileAsHex(file);

	fclose(file);

	system("pause");
	return 0;
}
//主要实现函数
void printFileAsHex(FILE* file)
{
	int count = 0;
	char buffer[LINELEN];                 //临时存放字符的数组

	while (1)
	{
		
		int byteVal = fgetc(file);        //指向的文件中读取一个字符，读取一个字节后，光标位置后移一个字节。
		
		if (EOF == byteVal)               //如果文件已经到尾部跳出循环
		{
			break;
		}
		
		buffer[count] = byteVal;          //将文件字符存储到数组中
		count++;                          //计算每个字符的数目
		
		if (count >= LINELEN)             //提前处理前16个字节
		{
			writeLine(buffer, LINELEN);
			count = 0;
		}
	}

	if (count > 0)                           //不满16字节的情况处理
	{
		writeLine(buffer, count);
	}
}

char toVisibleCharacter(int byteVal)
{
	if (byteVal >= 32 && byteVal <= 126)  // 输出可打印字符
	{
		return (char)byteVal;
	}

	return '_';                           //不可打印就输出_号
}

void writeLine(char* lineBuffer, int buflen)
{
	int i;

	char str[LINELEN];

	// 读写文件
	FILE* file = fopen("D:\\20171111-test.txt", "a+");

	for (i = 0; i < buflen; i++)
	{
		char chu = upperToHex(lineBuffer[i]); //取高4位  -->处理成十进制的值
		char chl = lowerToHex(lineBuffer[i]); //取低4位  -->处理成十进制的值
		printf("%c%c ", chu, chl);
		//自增加的-写文件到txt
		sprintf(str, "%c%c", chu, chl);
		fseek(file, 0, SEEK_END);
		fwrite(str, strlen(str), 1, file);
	}
	fclose(file);

	if (buflen < LINELEN)
	{
		for (i = LINELEN - buflen; i > 0; i--)
		{
			printf("   ");
		}
	}

	printf("\t");



	char str1[LINELEN];
	for (i = 0; i < buflen; i++)
	{
		char ch = toVisibleCharacter(lineBuffer[i]);
		printf("%c", ch);
	}

	printf(CRLF);
}

char upperToHex(int byteVal)
{
	int i = (byteVal & 0xF0) >> 4;  //0F二进制为00001111，低四位保留，然后右移4位，也就是只取出高4位的意思
	return nibbleToHex(i);
}

char lowerToHex(int byteVal)
{
	int i = (byteVal & 0x0F);  //保留低4位00001111，这次没有右移，所以保留低4位
	return nibbleToHex(i);
}

char nibbleToHex(int nibble)
{
	const int ascii_zero = 48;
	const int ascii_a = 65;

	if ((nibble >= 0) && (nibble <= 9))
	{
		return (char)(nibble + ascii_zero);   // 十六进制转换成十进制 返回数字，本来是int型，强转成char了
	}
	if ((nibble >= 10) && (nibble <= 15))
	{
		return (char)(nibble - 10 + ascii_a); // 十六进制转换成十进制的字母，本来是int型，强转成char了
	}
	return '?';                               //其余情况返回'?'
}

