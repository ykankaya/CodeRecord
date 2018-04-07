// 联合体.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "stdlib.h"
#include  <string.h>

union _TEMP
{
	char a;
	char b;

}g_T;

int _tmain(int argc, _TCHAR* argv[])
{
	union _TEMP v;
	v.a = 5;
	printf("v.a is %d\n", v.a);
	v.b = 6;
	printf("now v.a is %ld! the address is %p\n", v.a, &v.a);
	printf("now v.b is %d! the address is %p\n", v.b, &v.b);


	system("pause");

	//所以说，管union的叫共用体还真是贴切——完全就是共用一个内存首地址，并且各种变量名都可以同时使用，操作也是共同生效。如此多的access内存手段，确实好用，不过这些“手段”之间却没法互相屏蔽——就好像数组 + 下标和指针 + 偏移一样。

	//上例中我改了v.a的值，结果v.b也能读取，那么也许我还以为v.b是我想要的值呢，因为上边提到了union的内存首地址肯定是相同的，那么还有一种情况和上边类似：

	//一个int数组变量a，一个long int(32位机中，long int占4字节，与int相同)变量b，我即使没给int变量b赋值，因为数据类型相同，我使用int变量b也完全会拿出int数组a中的a[0]来，一些时候一不小心用上，还以为用的就是变量b呢~

	//这种逻辑上的错误是很难找出来的（只有当数据类型相去甚远的时候稍好，出个乱码什么的很容易发现错误）。



	return 0;
}
