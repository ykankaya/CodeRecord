

#include <stdio.h>

int main() {
	/*
	编程解决如下问题：鸡翁一，值钱五；鸡母一，值钱三；鸡雏三，值钱一。百钱买百鸡，
	问鸡翁，鸡母，鸡雏各几何？
	http://www.linuxidc.com/Linux/2012-03/56653.htm
	设公鸡为x，母鸡为y，小鸡为z
	可以得出如下的不定方程，
	x+y+z=100,
	5x+3y+z/3=100，
	*/

	/*
	上机错误记录
	1、FOR语句后面跟了;(分号)
	2、\n(换行符)需要小写，写成\N是不起作用的；
	*/


	static int x, y, z;
	for (z = 0;z <= 100;z++)
	{
		for (y = 0; y <= 100; y++)
		{
			for (x = 0; x <= 100; x++)
			{
				if (100 == x + y + z && 100 == 5 * x + 3 * y + z / 3 && 0 == z % 3)
				{
					printf("x=%d,y=%d,z=%d \n", x, y, z);
				}
			}
		}
	}
	return 0;
}