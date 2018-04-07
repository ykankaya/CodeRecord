#include<stdio.h>

#include<stdlib.h>

#include<string.h>

int main(void)

{
	double a, b, c;
	printf("输入三角形三条边的长度 \n ");
	scanf_s("%lf %lf %lf", &a,&b,&c);
	if (a + b > c&&a + c > b&&b + c > a)
	{
		if (a == b&&b == c){
			printf("等边三角形\n");
		}
		else if ((a == b&&b != c) || (b == c&&b != a) || (a == c&&a != b))
		{
			printf(" 等腰三角形\n ");
		}
		else{
		
			if (a*a+b*b==c*c||a*a+c*c==b*b||b*b+c*c==a*a)
			printf(" 直角三角形\n ");
		
		}

	}
	else{
		printf(" 不能构成三角形\n ");
	}
    system("pause");
    return 0;

}