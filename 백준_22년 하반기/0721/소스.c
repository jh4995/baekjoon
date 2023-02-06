#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable: 4996)

#include <stdio.h>

int main(void)
{
	//1 2~7 8~19 20~37
	/*
	[1]1
	[2]234567 ->6개                            (2+0 ~ 1+6) 
	[3]8910111213141516161819 -> 12개          (2+6 ~ 1+18)
	[4]202121 ---                3637 -> 18개  (2+18 ~ 1+36)
	[5]383940                      6061 -> 24개(2+36 ~ 1+60)
	[6]62 ~
	*/

	int n;
	int i = 1;

	int count = 1;
	int start = 2;
	//int end = 7;
	scanf("%d", &n);

	if (n == 1)
	{
		printf("%d", 1);
		return 0;
	}
	while (1)
	{
		count++;
		if (start <= n && n < start + (6 * i))
		{
			printf("%d", count);
			break;
		}
		else 
		{
			start = start + 6*i;
		}
		i++;
	}

	return 0;
}