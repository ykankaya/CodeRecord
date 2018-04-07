// 04_01_根据坦克结构体实现屏幕自由移动的坦克.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <process.h>
#include  <windows.h>
#include  <conio.h>




typedef struct _OBJECT
{
	COORD  oldPos;  /*旧位置*/
	COORD  newPos;  /*新位置*/
	char icon[8];  //图片样式

}OBJECT, *POBJECT;
//OBJECT g_obj = { { 0, 3 }, { 3, 3 }, "   ☆☆" };

OBJECT g_obj = { { 0, 3 }, { 3, 3 }, {} };



//1.定义地图数据(二维数组) 
int g_map[40][40] = {
	{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
	{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
	{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
	{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
	{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
	{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
	{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
	{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
	{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
	{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
	{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
	{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
	{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
	{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
	{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
	{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
	{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
	{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
	{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
	{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
	{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
	{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
	{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
	{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
	{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
	{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
	{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
	{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
	{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
	{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
	{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
	{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
	{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
	{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
	{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
	{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
	{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
	{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
	{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
	{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 }
};


//x坐标； y坐标；    
//需要打印的字符 
void PrintChar(int Wide, int High, char * pszChar)
{
	//1.设置光标属性
	CONSOLE_CURSOR_INFO cci;
	cci.dwSize = 1;
	cci.bVisible = FALSE;  //是否显示光标
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cci);
	//2.修改光标在控制台中的坐标位置
	COORD loc;
	loc.X = Wide * 2;
	loc.Y = High;
	//3.设置光标在控制台中的坐标位置
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), loc);
	printf("%s", pszChar);  //打印字符串

}
//PrintChar(10, 12, "  ☆☆");
//PrintChar(10, 13, "☆☆  ");
//PrintChar(10, 14, "  ☆☆");

//3.定位坦克出现位置
//void WriteChar(short row, short col, char *str)
//{
//	COORD pos = { 2 * col, row };
//	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
//	printf("%s", str);
//
//}

//6.定义初始坐标

bool Check(COORD pos)
{
	if (g_map[pos.Y][pos.X] == 0){
		return true;

	}
	return false;

}
//5.移动函数编写
void MoveObj(int key)
{
	switch (key)
	{
	case  'w':case 'W':case 72:
		PrintChar(g_obj.newPos.X, g_obj.newPos.Y,     "      ");
		PrintChar(g_obj.newPos.X, g_obj.newPos.Y + 1, "      ");
		PrintChar(g_obj.newPos.X, g_obj.newPos.Y + 2, "      ");

		g_obj.newPos.Y--;

		PrintChar(g_obj.newPos.X, g_obj.newPos.Y,     "  ☆  ");
		PrintChar(g_obj.newPos.X, g_obj.newPos.Y + 1, "☆☆☆");
		PrintChar(g_obj.newPos.X, g_obj.newPos.Y + 2, "☆  ☆");

		break;
	case  's':case 'S':case 80:
		PrintChar(g_obj.newPos.X, g_obj.newPos.Y,     "      ");
		PrintChar(g_obj.newPos.X, g_obj.newPos.Y + 1, "      ");
		PrintChar(g_obj.newPos.X, g_obj.newPos.Y + 2, "      ");
		
		g_obj.newPos.Y++;

		PrintChar(g_obj.newPos.X, g_obj.newPos.Y,    "☆  ☆");
		PrintChar(g_obj.newPos.X, g_obj.newPos.Y + 1,"☆☆☆");
		PrintChar(g_obj.newPos.X, g_obj.newPos.Y + 2,"  ☆  ");
		break;
	case  'a':case 'A':case 75:
		PrintChar(g_obj.newPos.X, g_obj.newPos.Y,    "      ");
		PrintChar(g_obj.newPos.X, g_obj.newPos.Y + 1,"      ");
		PrintChar(g_obj.newPos.X, g_obj.newPos.Y + 2,"      ");

		g_obj.newPos.X--;

		PrintChar(g_obj.newPos.X, g_obj.newPos.Y,     "  ☆☆");
		PrintChar(g_obj.newPos.X, g_obj.newPos.Y + 1, "☆☆  ");
		PrintChar(g_obj.newPos.X, g_obj.newPos.Y + 2, "  ☆☆");

		break;
	case  'd':case 'D':case 77:
		PrintChar(g_obj.newPos.X, g_obj.newPos.Y,     "      ");
		PrintChar(g_obj.newPos.X, g_obj.newPos.Y + 1, "      ");
		PrintChar(g_obj.newPos.X, g_obj.newPos.Y + 2, "      ");

		g_obj.newPos.X++;

		PrintChar(g_obj.newPos.X, g_obj.newPos.Y,     "☆☆  ");
		PrintChar(g_obj.newPos.X, g_obj.newPos.Y + 1, "  ☆☆");
		PrintChar(g_obj.newPos.X, g_obj.newPos.Y + 2, "☆☆  ");

		break;
	case VK_SPACE:  //case ' ';
		break;
	default:
		break;
	}



	bool  isOK = Check(g_obj.newPos);

	if (isOK){
		//擦除旧的
		//WriteChar(g_obj.oldPos.Y, g_obj.oldPos.X, " ");
		PrintChar(g_obj.oldPos.Y, g_obj.oldPos.X, "      ");


		g_obj.oldPos = g_obj.newPos;
		//画出新的

		//WriteChar(g_obj.newPos.Y, g_obj.oldPos.X, g_obj.icon);

		PrintChar(g_obj.newPos.Y, g_obj.oldPos.X, g_obj.icon);
	}
	else{

		g_obj.newPos = g_obj.oldPos;

	}
}




//4.1 接收用户按键
int GetMessage()
{
	if (_kbhit())
	{
		return _getch();
	}
	return 0;
}




//2.打印地图函数编写
void DrawMap(int(*pMap)[40])
{
	for (size_t i = 0; i < 40; i++)
	{
		for (size_t j = 0; j < 40; j++)
		{
			if (pMap[i][j] == 0)
			{
				//WriteChar(i, j, " ");
				PrintChar(i, j, " ");
			}
			else if (pMap[i][j] == 1)
			{
				PrintChar(i, j, "■");
				//WriteChar(i, j, "■");
			}
		}
	}
}

int _tmain(int argc, _TCHAR* argv[])
{

	//1.定义地图数据(二维数组) 
	//2.打印地图函数编写
	DrawMap(g_map);
	//3.定位坦克出现位置

	/*4、接收用户按键*/
	while (true)
	{
		//4.1.接收用户按键
		int ch = GetMessage();

		if (ch == 0)
		{
			continue;
		}
		//5.移动函数编写
		MoveObj(ch);

	}
	//6.定义初始坐标、

	system("pause");

	return 0;
}

