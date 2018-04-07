#include<stdio.h>

#include<stdlib.h>

#include<string.h>

int main(void)

{
	int nNum, hun, ten, gw, sum;
	for (nNum = 100; nNum < 999; nNum++)
	{
		hun = nNum / 100;                       //取百位
		ten = nNum / 10 % 10 ;                  //取十位
		gw = nNum % 10;                         //取个位
		sum = hun*hun*hun + ten*ten*ten + gw*gw*gw;
		if (nNum == sum)
		{
			printf(" %d 是水仙花数 \n ",nNum);
		}
	}

    system("pause");
    return 0;

}