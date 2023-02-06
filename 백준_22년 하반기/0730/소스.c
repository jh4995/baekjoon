#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable: 4996)

#include <stdio.h>
/*
int main(void)
{
	       [x]
	숫자 합 2[1]        1/1
	숫자 합 3[2,3]      1/2, 2/1
	숫자 합 4[4,5,6]    3/1, 2/2, 1/3
	숫자 합 5[7,8,9,10] 1/4, 2/3, 3/2, 4/1
	숫자 합 6[11,12,13,14,15] 5/1, 4/2, 3/3, 2/4, 1/5

	1 12 321 1234
	1 21 123 4321
	

	int hap = 3;
	int start = 2;
	int front, rear;
	int x;
	scanf("%d", &x);

	if (x == 1)
	{
		printf("1/1");
		return 0;
	}
	
	while (1)
	{
		if (start <= x && x <= start + hap -2)
		{

		}
		start = start + (hap - 2);
	}

	//printf("%d/%d", , );
	return 0;
}*/

int main(void)
{
	int x;
	scanf("%d", &x);

	int line = 1;
	while (1) 
	{
		if ((line - 1) * (line) / 2 < x && x <= (line) * (line + 1) / 2)
		{
			break;
		}
		line++;
	}

	if (line % 2 != 0)
	{
		int a = line * (line + 1) / 2;
		printf("%d/%d", a - x + 1, line - (a - x));
	}
	else
	{
		int a = line * (line + 1) / 2;
		printf("%d/%d", line - (a - x), a - x + 1);
	}

	return 0;
}