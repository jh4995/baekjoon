#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable: 4996)

#include <stdio.h>

/*
int divide_hap(int n)
{
	int mid_result = n;

	while (n > 0)
	{
		mid_result = mid_result + (n %10);
		n = n / 10;
	}

	return mid_result;

}

int main(void)
{
	int n;
	scanf("%d", &n);

	for (int i = 1; i <= n; i++)
	{
		if (divide_hap(i) == n)
		{
			printf("%d\n", i);
			break;
		}

		if (i == n)
		{
			printf("%d", 0);
		}
	}
	return 0;
}*/

int main(void)
{
	int n, x, y;
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		scanf("%d %d", &x, &y);
	}

	return 0;
}