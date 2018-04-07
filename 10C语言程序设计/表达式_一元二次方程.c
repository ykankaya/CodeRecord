#include<stdio.h>

#include<stdlib.h>
#include<stdio.h>

#include<stdlib.h>
#include<math.h>
#include<string.h>

int main(void)
{

	//解题思路：
	//	1、a=0，不是二次方程；
	//	2、b*b-4 * b * c=0 有两个相等实根
	//					>0，有两个不等实根
	//					<0，有两个共轭复根

	double a, b, c, disc, x1, x2, realpart, imagpart;
	scanf_s("%lf %lf %lf", &a, &b, &c);
	printf("输入值");
	/*a的绝对值小于等于10的 - 6次, 一般是等于0*/
	if (fabs(a)<=0)
		printf("a<=0 ,所以没有实根\n");
	else
	{
		disc = b * b - 4 * a * c;
		if (fabs(disc) <= 0)
			printf("两个相等的实根：%8.4f \n", -b / (2 * a));
		else
			if (disc > 0)
			{
				x1 = (-b + sqrt(disc) / (2 * a));
				x2 = (-b - sqrt(disc)) / (2 * a);
				printf("有两个不等实根：%8.4f and %8.4f \n", x1, x2);
			}
			else{
				realpart = -b / (2 * a);
				imagpart = sqrt(disc) / (2 * a);
				printf("有两个共轭复根：\n");
				printf("%8.4f+%8.4f\n", realpart, imagpart);
				printf("%8.4f-%8.4f", realpart, imagpart);
			}
	}
    system("pause");
    return 0;

}