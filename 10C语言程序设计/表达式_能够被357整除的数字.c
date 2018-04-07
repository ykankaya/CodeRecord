#include<stdio.h>

#include<stdlib.h>

#include<string.h>

int main(void)

{
	long nNum;
	printf("enter two number \n");
	scanf_s("%d", &nNum);

	/*条件1：能同时被3、5、7整除 */
	/* 能被3,5,7整除 */
	if (nNum % 3 == 0 && nNum % 5 == 0 && nNum % 7 == 0)
	{
		printf("%d能被3,5,7整除的数字 \n", nNum);
		/*能被5,7整除*/
		if (nNum % 5 == 0 && nNum % 7 == 0)
		{
			printf("%d 能被5,7整除的数字 \n", nNum);
		}
		else if (nNum % 3 == 0)
		{
			printf("%d能被3整除的数字 \n", nNum);
		}
		else if (nNum % 5 == 0)
		{
			printf("%d能被5整除的数字 \n", nNum);
		}
		else if (nNum % 7 == 0)
		{
			printf("%d能被7整除的数字 \n", nNum);
		}else
		{
			printf("%d 不能被3,5,7整除的数字 \n", nNum);
		}
	}

	/*条件2：能被其中两个数整除*/
	if (nNum % 3 == 0 && nNum % 5 == 0)
	{
		printf("%d 能被3、5整除的数字 \n",nNum);
	}
	else if (nNum % 5 == 0 && nNum % 7 == 0)
	{
		printf("%d 能被5、7整除的数字 \n", nNum);
	}else if (nNum % 3 == 0 && nNum % 7 == 0)
	{
		printf("%d 能被3、7整除的数字 \n", nNum);
	}
	else{
		printf("%d 不能同时被两个数整除的数字 \n", nNum);
	}

	/*条件3：能被其中一个数整除*/
	if (nNum % 3 == 0 )
	{
		printf("%d 能被3整除的数字 \n", nNum);
	}
	else if (nNum % 5 == 0 )
	{
		printf("%d 能被5整除的数字 \n", nNum);
	}
	else if (nNum % 7 == 0)
	{
		printf("%d 能被7整除的数字 \n", nNum);
	}
	else
	{
		printf("%d 不能被3,5,7 任何一个数字整除的数字 \n", nNum);
	}

	
    system("pause");
    return 0;

}