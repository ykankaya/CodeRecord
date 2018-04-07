#include<stdio.h>

#include<stdlib.h>

#include<string.h>

int main(void)

{
	int nNum = 0;
	printf(" 输入一个数字 \n ");
	scanf_s("%d", &nNum);

	switch (nNum)
	{
	case 1: printf(" %d 这是星期一 \n ", nNum);
		break;
	case 2: printf(" %d 这是星期二 \n ", nNum); 
		break;
	case 3: printf(" %d 这是星期三 \n ", nNum); 
		break;
	case 4: printf(" %d 这是星期四 \n ", nNum); 
		break;
	case 5: printf(" %d 这是星期五 \n ", nNum); 
		break;
	case 6: printf(" %d 这是星期六 \n ", nNum); 
		break;
	case 7: printf(" %d 这是星期日 \n ", nNum); 
		break;

	default:
		break;
	}
    system("pause");
    return 0;

}