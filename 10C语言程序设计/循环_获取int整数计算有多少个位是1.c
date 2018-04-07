#include<stdio.h>

#include<stdlib.h>

#include<string.h>

int main(void)

{
	int sum = 0;
	int nNum,Tmep;




	printf(" 输入一个整数，判断有多少个位是1 \n ");
	scanf_s("%d", &nNum);

loop: if(nNum)
	{
		Tmep = nNum % 10;
		nNum = nNum / 10;
		if (Tmep==1)
		{
			sum++;
		}
		goto loop;

	}


	printf(" 计算出这个整数有 →    %d    ←个位是1 \n ",sum);
    system("pause");
    return 0;

}