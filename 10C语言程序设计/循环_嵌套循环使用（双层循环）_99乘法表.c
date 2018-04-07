#include<stdio.h>

#include<stdlib.h>

#include<string.h>




int main(void)

{

	for (int row = 1; row <= 9; row++){  //打印0-8，一共九次；
		for (int col = 1; col <= row; col++){  //控制每一次怎么打印
			printf("%d * %d = %2d   ", col,row,col*row);
		}
		printf("\n");
	}
    system("pause");
    return 0;

}