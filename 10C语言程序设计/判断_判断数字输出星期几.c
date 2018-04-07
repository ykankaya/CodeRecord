#include<stdio.h>

#include<stdlib.h>

#include<string.h>

int main(void)

{
	int nNum = 0;

	printf(" 输入一个数字 \n ");

	scanf_s("%d", &nNum);

	if (nNum == 1){
		printf(" %d 这是星期一 \n ", nNum);
	}
	else if (nNum == 2){
		printf(" %d 这是星期二 \n ", nNum);
	}
	else if (nNum == 3){
		printf(" %d 这是星期三 \n ", nNum);
	}
	else if (nNum == 4){
		printf(" %d 这是星期四 \n ", nNum);
	}
	else if (nNum == 5){
		printf(" %d 这是星期五 \n ", nNum);
	}
	else if (nNum == 6){
		printf(" %d 这是星期六 \n ", nNum);
	}
	else if (nNum == 7){
		printf(" %d 这是星期日 \n ", nNum);
	}


    system("pause");
    return 0;

}