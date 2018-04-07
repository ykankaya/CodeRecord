#include<stdio.h>

#include<stdlib.h>

#include<string.h>

int main(void)

{
	int nNum;
	printf(" \t\t\t**************************************  \n ");
	printf(" \t\t\t*           1   One Player           *  \n ");
	printf(" \t\t\t*           2   Two Player           *  \n ");
	printf(" \t\t\t*           3   Edit Player          *  \n ");
	printf(" \t\t\t*           4   Chose Player         *  \n ");
	printf(" \t\t\t**************************************  \n ");

	printf(" 请选项所对应的数字 输入一个数字 \n ");
	scanf_s("%d", &nNum);

	switch (nNum)
	{
	case 1 : printf(" 你选择了 One Player \n " ); 
		break;
	case 2 : printf(" 你选择了 Two Player \n ");
		break;
	case 3 : printf(" 你选择了 Edit Player \n ");
		break;
	case 4 : printf(" 你选择了 Chose Player \n ");
		break;
	default:
		break;
	}
    system("pause");
    return 0;

}