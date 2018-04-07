#include<stdio.h>

#include<stdlib.h>

#include<string.h>

#include<math.h>

int main(void)

{

	/*  6、利用海伦公式求出三角形面积，三边长a，b，c由键盘输入。若输入的三边长不能构成三角形，输出相应提示信息
	 *	海伦公式：其中s=(a+b+c)/2
	 *  三角形面积: √s*(s-a)*(s-b)*(s-c)
	 */
	
	double nNuma, nNumb, nNumc;
	double s , area;


	printf(" 输入三角形的三边长，格式如【a b c】\n 例如【2.0 3.0 4.0】 \n ");
	scanf_s("%lf%lf%lf", &nNuma, &nNumb,&nNumc);
	

	s = (nNuma + nNumb + nNumc) / 2.0;
	area = sqrt(s*(s - nNuma)*(s - nNumb)*(s - nNumc));

	printf(" a = %7.2f \t b = %7.2f c = %7.2f \n ",nNuma,nNumb,nNumc);
	printf(" area = %7.2f \n ",area);
    system("pause");
    return 0;

}