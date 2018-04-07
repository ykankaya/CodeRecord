#include<stdio.h>

#include<stdlib.h>

#include<string.h>

int main(void)

{
	int nYear, nMonth;

	printf(" 输入年份与月份，格式如【2016 8】、【2016 12】 \n ");
	scanf_s("%d %d", &nYear,&nMonth);

	if ((nYear % 4 == 0 && nYear % 100 != 0) || (nYear % 400 == 0))
	{

		printf(" %d 为闰年 \n ", nYear);
		switch (nMonth)
		{
		case 1 :  printf(" 该季节为冬天，这个月天数有31天 \n "); break;
		case 2:   printf(" 该季节为春天，这个月天数有29天 \n "); break;
		case 3:   printf(" 该季节为春天，这个月天数有31天 \n "); break;
		case 4:   printf(" 该季节为春天，这个月天数有30天 \n "); break;
		case 5:   printf(" 该季节为夏天，这个月天数有31天 \n "); break;
		case 6:   printf(" 该季节为夏天，这个月天数有30天 \n "); break;
		case 7:   printf(" 该季节为夏天，这个月天数有31天 \n "); break;
		case 8:   printf(" 该季节为秋天，这个月天数有31天 \n "); break;
		case 9:   printf(" 该季节为秋天，这个月天数有30天 \n "); break;
		case 10:  printf(" 该季节为秋天，这个月天数有31天 \n "); break;
		case 11:  printf(" 该季节为冬天，这个月天数有30天 \n "); break;
		case 12: printf(" 该季节为冬天，这个月天数有31天 \n "); break;

		default:
			break;
		}
	}
	else
	{
		printf(" %d 不为闰年 \n ", nYear);
		switch (nMonth)
		{
		case 1:  printf(" 该季节为冬天，这个月天数有31天 \n "); break;
		case 2:   printf(" 该季节为春天，这个月天数有30天 \n "); break;
		case 3:   printf(" 该季节为春天，这个月天数有31天 \n "); break;
		case 4:   printf(" 该季节为春天，这个月天数有30天 \n "); break;
		case 5:   printf(" 该季节为夏天，这个月天数有31天 \n "); break;
		case 6:   printf(" 该季节为夏天，这个月天数有30天 \n "); break;
		case 7:   printf(" 该季节为夏天，这个月天数有31天 \n "); break;
		case 8:   printf(" 该季节为秋天，这个月天数有31天 \n "); break;
		case 9:   printf(" 该季节为秋天，这个月天数有30天 \n "); break;
		case 10:  printf(" 该季节为秋天，这个月天数有31天 \n "); break;
		case 11:  printf(" 该季节为冬天，这个月天数有30天 \n "); break;
		case 12: printf(" 该季节为冬天，这个月天数有31天 \n "); break;

		default:
			break;
		}
	}

    system("pause");
    return 0;

}