#include<stdio.h>

#include<stdlib.h>

#include<string.h>

int main(void)

{
	int a, b, c, d, e,i , aver ;

	for (i = 1; i <= 6;i++)
	{
		printf(" 输入第%d名学生成绩\n ",i);
		scanf_s("%d%d%d%d%d", &a, &b, &c , &d, &e);
		aver = (a + b + c + d + e) /5;
		printf("\t 第%d名的同学成绩分别是：%d %d %d %d %d  \n\t 平均成绩是： %d \n ",i,a,b,c,d,e,aver);
	}


	system("pause");
    return 0;

}